#include <iostream>
#include <vector>

using namespace std;

class vertex
{
private:
    int key;
    int value;

    vertex *parent;
    vector<vertex *> children;

public:
    void init(int _key);
    void adoptChild(vertex *_child);
    void admitParent(vertex *_parent);

    int getKey(void);
    int getValue(void);
    vector<vertex *> getChildren(void);
    vertex *getParent(void);

    int tourTree(void);
};

void vertex::init(int _key)
{
    parent = NULL;
    key = _key;
}

void vertex::adoptChild(vertex *_child)
{
    children.push_back(_child);
}

void vertex::admitParent(vertex *_parent)
{
    parent = _parent;
}

vector<vertex *> vertex::getChildren(void) { return children; }

vertex *vertex::getParent(void) { return parent; }

int vertex::getKey(void) { return key; }

int vertex::getValue(void) { return value; }

int vertex::tourTree(void)
{
    if (children.size() == 0)
        return value;

    int tourMaxRadian = 0;

    for (auto &childTour : children)
    {
        int tourRadian = childTour->tourTree();

        if (tourRadian > tourMaxRadian)
        {
            tourMaxRadian = tourRadian;
        }
    }

    return tourMaxRadian + valueu;
}

int main(void)
{
    return 0;
}