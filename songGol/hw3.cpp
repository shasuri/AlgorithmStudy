#include <iostream>
#include <string>

using namespace std;

bool maze[7][7];  // given table
string path;      // input path
int routeCnt = 0; // number of route

void travel(int depth, int col, int row, char dir)
// depth : steps we moved
// col : our column location
// row : our row location
// dir : previous move direction, first one is 'I', intializing
{

    if (col == 6 && row == 0) // If we get to the destination(7,1)
    {
        if (depth == 48)   // and visit all other 48 spaces,
            routeCnt += 1; // that means we found the route. So add 1 route counter.
        return;            // And get back to find other way.
    }

    switch (dir) // Action divided by our previous direction
    // check next space is blocked -> check side spaces are not both blocked -> then this branch is pruned!
    {
    case 'U': // we moved up,
        if ((col == 0 || maze[col - 1][row]) && (row - 1 > -1 && row + 1 < 7) && !(maze[col][row - 1] || maze[col][row + 1]))
            return;
        break;

    case 'D': // we moved down,
        if ((col == 6 || maze[col + 1][row]) && (row - 1 > -1 && row + 1 < 7) && !(maze[col][row - 1] || maze[col][row + 1]))
            return;
        break;

    case 'L': // we moved left,
        if ((row == 0 || maze[col][row - 1]) && (col - 1 > -1 && col + 1 < 7) && (!(maze[col - 1][row] || maze[col + 1][row])))
            return;
        break;

    case 'R': // we moved right,
        if ((row == 6 || maze[col][row + 1]) && (col - 1 > -1 && col + 1 < 7) && (!(maze[col - 1][row] || maze[col + 1][row])))
            return;
        break;

    default: // for initialized one.
        break;
    }

    maze[col][row] = true; // Record this space is visited

    switch (path[depth]) // Action divided by the index of given path.
    {
    // Path commands to
    case 'U':                                     // go up.
        if (col - 1 > -1 && !maze[col - 1][row])  // Check next space is not blocked.
            travel(depth + 1, col - 1, row, 'U'); // Then go to the space.
        break;

    case 'D': // go down.
        if (col + 1 < 7 && !maze[col + 1][row])
            travel(depth + 1, col + 1, row, 'D');
        break;

    case 'L': // go left
        if (row - 1 > -1 && !maze[col][row - 1])
            travel(depth + 1, col, row - 1, 'L');
        break;

    case 'R': // go right.
        if (row + 1 < 7 && !maze[col][row + 1])
            travel(depth + 1, col, row + 1, 'R');
        break;

    case '?': // Branches are divided, check each spaces, and then go to four way.
        if (col - 1 > -1 && !maze[col - 1][row])
            travel(depth + 1, col - 1, row, 'U');

        if (col + 1 < 7 && !maze[col + 1][row])
            travel(depth + 1, col + 1, row, 'D');

        if (row - 1 > -1 && !maze[col][row - 1])
            travel(depth + 1, col, row - 1, 'L');

        if (row + 1 < 7 && !maze[col][row + 1])
            travel(depth + 1, col, row + 1, 'R');

        break;

    default:
        break;
    }

    maze[col][row] = false; // Recursion function is returned, then record it not visited.
    return;
}

int main()
{
    cin >> path; // path input

    travel(0, 0, 0, 'I');     // travel the table(maze) 'I' doesn't mean anything, just initializing
    cout << routeCnt << endl; // print out number of route
}