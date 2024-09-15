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
    Node* tail;
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

    void Lins(int x)  // Inserting at the last/end
    {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            Node* ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = temp;
        }
        size++;
    }

    void Lins(int x)  // Inserting at the last/end  // With tail pointer
    {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
};