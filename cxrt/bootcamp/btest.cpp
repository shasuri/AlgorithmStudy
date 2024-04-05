#include <iostream>
#include <queue>
using namespace std;

struct Point
{
    int y;
    int x;

    Point operator-(int i){
        Point p;
        p.x = x - i;
        p.y = y - i;

        return p;
    }
};


int main(void)
{
    cout << ((-1) % 4)<< endl;
}