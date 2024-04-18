// #define DEBUG_MODE

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

enum SpaceType
{
    OUT_RECT,
    IN_RECT,
    EDGE
};

enum Side
{
    RIGHT,
    LEFT,
    DOWN,
    UP
};

typedef short EdgeType;

struct Space
{
    SpaceType spaceType = OUT_RECT;
    bool visited = false;
    EdgeType edgeType = 0;
    /*
        0000 NONE

        0001 RIGHT
        0010 LEFT
        0100 DOWN
        1000 UP

        0101 RIGHT DOWN
        1001 RIGHT UP
        0110 LEFT DOWN
        1010 LEFT UP

        R + D = LU
        L + D = RU
        R + U = LD
        L + U = RD
    */
};

struct Loc
{
    short y;
    short x;
    int step;
};

#ifdef DEBUG_MODE
const short MAXB = 15;
#else
const short MAXB = 52;
#endif
const short DIR = 4;
const short REV_MASK = (1 << DIR) - 1;
const short DIR_Y[] = {0, 0, 1, -1};
const short DIR_X[] = {1, -1, 0, 0};

// UDLR
const short RD_SIDE = (1 << RIGHT) | (1 << DOWN);
const short LD_SIDE = (1 << LEFT) | (1 << DOWN);
const short RU_SIDE = (1 << RIGHT) | (1 << UP);
const short LU_SIDE = (1 << LEFT) | (1 << UP);
const short R_SIDE = (1 << RIGHT);
const short L_SIDE = (1 << LEFT);
const short D_SIDE = (1 << DOWN);
const short U_SIDE = (1 << UP);

Space map[MAXB][MAXB];

void setMap(vector<vector<int>> &rectangle);
void setEdgeType(Space &s, Side d);
EdgeType reverseEdgeType(EdgeType e);
void printMap(void);
wchar_t convertIcon(Space s);
int travelLine(const Loc character, const Loc item);
bool checkMovable(Loc l, Side d);
bool checkInMap(Loc l);
bool checkAtLine(Loc l);

// #ifdef DEBUG_MODE
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY);
int main(void)
{
    vector<vector<int>> r = {{1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}};
    solution(r, 1, 3, 7, 8);
    cout << "run";
}
// #endif

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;

    setMap(rectangle);
#ifndef DEBUG_MODE
    Loc character = {static_cast<short>(characterY), static_cast<short>(characterX), 0};
    Loc item = {static_cast<short>(itemY), static_cast<short>(itemX), 0};
    return travelLine(character, item);
#else
    printMap();
    return 0;
#endif
}

void setMap(vector<vector<int>> &rectangle)
{
    Loc leftTop, rightBot;
    for (auto r : rectangle)
    {
        leftTop.y = r[1];
        leftTop.x = r[0];
        rightBot.y = r[3];
        rightBot.x = r[2];

        for (int h = leftTop.y; h <= rightBot.y; h++)
        {
            for (int w = leftTop.x; w <= rightBot.x; w++)
            {
                if (w == leftTop.x || w == rightBot.x || h == leftTop.y || h == rightBot.y)
                {
                    switch (map[h][w].spaceType)
                    {
                    case IN_RECT:
                        break;

                    case EDGE:
                    case OUT_RECT:
                        if (w == rightBot.x)
                        {
                            setEdgeType(map[h][w], RIGHT);
                        }
                        if (w == leftTop.x)
                        {
                            setEdgeType(map[h][w], LEFT);
                        }
                        if (h == leftTop.y)
                        {
                            setEdgeType(map[h][w], UP);
                        }
                        if (h == rightBot.y)
                        {
                            setEdgeType(map[h][w], DOWN);
                        }

                        if (map[h][w].spaceType == EDGE)
                        {
                            map[h][w].edgeType = reverseEdgeType(map[h][w].edgeType);
                        }

                        map[h][w].spaceType = EDGE;
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    map[h][w].spaceType = IN_RECT;
                }
            }
        }
    }
}

void setEdgeType(Space &s, Side d)
{
    s.edgeType |= (1 << d);
}

EdgeType reverseEdgeType(EdgeType e)
{
    return e ^ REV_MASK;
}

#ifndef DEBUG_MODE

int travelLine(const Loc character, const Loc item)
{
    queue<Loc> locQue;
    map[character.y][character.x].visited = true;
    locQue.push(character);

    Loc cur, next;
    
    while (!locQue.empty())
    {
        cur = locQue.front();
        locQue.pop();

        // R - L - D - U
        for (short i = 0; i < DIR; i++)
        {
            // Loc next = {cur.y + DIR_Y[i], cur.x + DIR_X[i], cur.step + 1};
            next.y = cur.y + DIR_Y[i];
            next.x = cur.x + DIR_X[i];
            next.step = cur.step + 1;
            
            if (checkInMap(next) && !map[next.y][next.x].visited && checkMovable(cur, static_cast<Side>(i)))
            {

                if (next.y == item.y && next.x == item.x)
                {
                    return next.step;
                }

                map[next.y][next.x].visited = true;

                if (checkAtLine(next))
                {
                    locQue.push(next);
                }
            }
        }
    }

    return -1;
}

bool checkMovable(Loc l, Side d)
{
    switch (map[l.y][l.x].edgeType)
    {
    case L_SIDE:
    case R_SIDE:
        return (1 << d) & (U_SIDE | D_SIDE);
        break;
    case U_SIDE:
    case D_SIDE:
        return (1 << d) & (L_SIDE | R_SIDE);
        break;
    case RD_SIDE:
    case RU_SIDE:
    case LD_SIDE:
    case LU_SIDE:
        return (1 << d) & reverseEdgeType(map[l.y][l.x].edgeType);
        break;

    default:
        break;
    }
    return false;
}

bool checkInMap(Loc l)
{
    return l.y >= 0 && l.y < MAXB && l.x >= 0 && l.x < MAXB;
}

bool checkAtLine(Loc l)
{
    return map[l.y][l.x].spaceType == EDGE;
}

#endif

#ifdef DEBUG_MODE
#include <clocale>

const wchar_t OUT_RECT_ICON = u'*';
const wchar_t IN_RECT_ICON = u' ';
const wchar_t LU_EDGE_ICON = u'┌';
const wchar_t RU_EDGE_ICON = u'┐';
const wchar_t LD_EDGE_ICON = u'└';
const wchar_t RD_EDGE_ICON = u'┘';
const wchar_t UD_EDGE_ICON = u'─';
const wchar_t LR_EDGE_ICON = u'│';

void printMap(void)
{
    setlocale(LC_CTYPE, "");
    // for (int i = MAXB - 1; i >= 0; i--)
    for (int i = 0; i < MAXB; i++)
    {
        for (int j = 0; j < MAXB; j++)
        {
            wcout << convertIcon(map[i][j]);
        }
        wcout << '\n';
    }
}

wchar_t convertIcon(Space s)
{
    switch (s.spaceType)
    {
    case OUT_RECT:
        return OUT_RECT_ICON;
        break;
    case IN_RECT:
        return IN_RECT_ICON;
        break;
    case EDGE:
        switch (s.edgeType)
        {
        case RD_SIDE:
            return RD_EDGE_ICON;
            break;
        case LD_SIDE:
            return LD_EDGE_ICON;
            break;
        case RU_SIDE:
            return RU_EDGE_ICON;
            break;
        case LU_SIDE:
            return LU_EDGE_ICON;
            break;
        case R_SIDE:
        case L_SIDE:
            return LR_EDGE_ICON;
            break;
        case D_SIDE:
        case U_SIDE:
            return UD_EDGE_ICON;
            break;
        default:
            return u'X';
            break;
        }
        break;
    default:
        return u'D';
        break;
    }
}

#endif
