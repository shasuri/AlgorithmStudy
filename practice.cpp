#include <iostream>

using namespace std;

int memPoolCnt;

struct Node
{
    int idx = -1;
    int value;
    Node *prev;
    Node *next;
} node[50000];

Node head, tail;

int main(void)
{
    head.next = &tail;
    tail.prev = &head;

    pushNode(getNewNode(1));

    getNodeByIdx(0);

    popNode();
}

Node* getNewNode(int value){
    Node* newNode = &node[memPoolCnt++];
    newNode->idx = memPoolCnt - 1;
    newNode->value = value;

    return newNode;
}

Node* getNodeByIdx(int idxFind){
    Node* ptr = head.next;
    int idxFind = 0;
    
    do {
        if(ptr->idx == idxFind || ptr->idx == -1) break;

        ptr = ptr->next;
    } while (ptr->next);

    return ptr;
}

void pushNode(Node* nodePush){
    
    nodePush->next = &tail;
    nodePush->prev = tail.prev;

    tail.prev->next = nodePush;
    tail.prev = nodePush;
}

Node* popNode(void){
    Node* nodePop = tail.prev;

    nodePop->next = nullptr;
    nodePop->prev->next = &tail;
    
    nodePop->prev = nullptr;
    tail.prev = nodePop->prev;

    return nodePop;
}