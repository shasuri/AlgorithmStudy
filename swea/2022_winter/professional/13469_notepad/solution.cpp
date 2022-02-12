
// #include <iostream>
using namespace std;
struct Character
{
    char content;
    Character *next;
    Character *prev;
} characters[90002];

struct Cursor
{
    Character *character;
    int height = 0;
    int width = 0;
};

Character *head = &characters[0];
Character *tail = &characters[1];
Cursor cursor;

int noteHeight;
int noteWidth;

int strSize;
int charCount;
/*
void printStr(void)
{
    Character *ptr = head;
    while (1)
    {
        cout << ptr->content;
        if ((ptr->content) == '$')
            break;

        ptr = ptr->next;
    }
    cout << endl;
}
*/

int getIndex(int height, int width)
{
    return height * noteWidth + width;
}

void init(int H, int W, char mStr[])
{
    charCount = 2;
    *tail = {'$', nullptr, head};
    *head = {'%', tail, nullptr};

    noteHeight = H;
    noteWidth = W;

    Character *ptr = head;

    int i = 0;
    while (mStr[i] != '\0')
    {

        Character *newChar = &characters[charCount++];
        *newChar = {mStr[i++], nullptr, nullptr};

        (newChar)->prev = ptr;
        (newChar)->next = ptr->next;
        ptr->next->prev = newChar;
        ptr->next = newChar;

        ptr = ptr->next;
    }

    strSize = i;

    cursor.height = 0;
    cursor.width = 0;
    cursor.character = head;
    // printStr();
}

void insert(char mChar)
{

    Character *newChar = &characters[charCount++];
    *newChar = {mChar, nullptr, nullptr};
    Character *cursorChar = cursor.character;

    newChar->prev = cursorChar;
    newChar->next = cursorChar->next;
    cursorChar->next->prev = newChar;
    cursorChar->next = newChar;

    cursor.character = newChar;

    if ((cursor.width) >= noteWidth - 1)
    {
        (cursor.width) = 0; // -1 can change
        (cursor.height)++;
    }
    else
        (cursor.width)++;

    strSize++;
}

char moveCursor(int mRow, int mCol)
{
    mRow--;
    mCol--;

    if (strSize < getIndex(mRow, mCol))
    {
        cursor.character = tail->prev;
        cursor.width = strSize % noteWidth;
        cursor.height = strSize / noteWidth;
        return '$';
    }

    int moveCount =
        noteWidth * (mRow - (cursor.height)) + (mCol - (cursor.width));

    if (moveCount > 0)
        for (int i = 0; i < moveCount; i++)
            cursor.character = cursor.character->next;
    else
        for (int i = 0; i < moveCount * (-1); i++)
            cursor.character = cursor.character->prev;

    cursor.height = mRow;
    cursor.width = mCol;
    // printStr();
    return cursor.character->next->content;
}

int countCharacter(char mChar)
{

    int searchCount = 0;

    Character *ptr = cursor.character->next;
    while (1)
    {
        if ((ptr->content) == mChar)
            searchCount++;

        if ((ptr->content) == '$')
            break;

        ptr = ptr->next;
    }

    // printStr();
    return searchCount;
}
