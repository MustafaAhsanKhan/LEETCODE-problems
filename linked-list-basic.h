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

    void Sins(int x)  // Inserting at the start
    {
        Node* temp = new Node;
        temp->data = x;

        if(head == NULL)
        {
            temp->next = NULL;
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
};