struct Character
{
    char content;
    Character* next;
    Character* prev;
};

struct Cursor
{
    Character* character;
    int height = 0;
    int width = 0;
};


Character* head;
Character* tail;
Cursor* cursor;

int noteHeight;
int noteWidth;

int strSize;

int getIndex(int height, int width)
    return height * noteWidth + width;

void init(int H, int W, char mStr[])
{
    Character headChar = {'%',tail,nullptr};
    Character tailChar = {'$',nullptr,head};
    head = &headChar;
    tail = &tailChar;

    noteHeight = H;
    noteWidth = W;
	
    Character* ptr = head;

    int i = 0;
    while(mStr[i] != '\0'){
        Character newChar = {mStr[i++],nullptr,nullptr};

        (&newChar) -> prev = ptr;        
        (&newChar) -> next = ptr -> next;
        ptr -> next -> prev = &newChar;
        ptr -> next = &newChar;

        ptr = ptr -> next;
    }

    strSize = i;
    cursor -> character = head;
}

void insert(char mChar)
{
    Character newChar = {mChar,nullptr,nullptr};
    Character* cursorChar = cursor -> character;
    
    (&newChar) -> prev = cursorChar;
    (&newChar) -> next = cursorChar -> next;
    cursorChar -> next -> prev = &newChar;
    cursorChar -> next = &newChar;

    cursorChar = &newChar;
    
    if((cursor -> width) + 1 > noteWidth){
        (cursor -> width) = 0; // -1 can change
        (cursor -> height)++;
    }
    else (cursor -> width)++;

    strSize++;
}

char moveCursor(int mRow, int mCol)
{    
    mRow--;
    mCol--;
    int moveCount = 
        noteWidth * ((cursor -> height) - mRow)
                + ((cursor -> width) - mCol);

    Character* ptr = cursor -> character;

    if(moveCount > 0)
        for(int i = 0; i < moveCount; i++) ptr = ptr -> prev;
    else
        for(int i = 0; i < moveCount; i++) ptr = ptr -> next;

    return ptr -> next -> content;
}

int countCharacter(char mChar)
{
	return -1;
}
