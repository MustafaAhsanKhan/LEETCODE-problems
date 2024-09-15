#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
    private:
    Node* head;
    int size;

    public:
    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    
};