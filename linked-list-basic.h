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
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void Sins(int x)  // Inserting at the start
    {
        Node* temp = new Node;
        temp->data = x;

        if (head == nullptr)
        {
            temp->next = nullptr;
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void Lins(int x)  // Inserting at the last/end
    {
        Node* temp = new Node;
        temp->data = x;
        temp->next = nullptr;

        if(head == nullptr)
        {
            head = temp;
        }
        else
        {
            Node* ptr = head;
            while(ptr->next != nullptr)
            {
                ptr = ptr->next;
            }

            ptr->next = temp;
        }
        size++;
    }

    void Lins_W_Tail(int x)  // Inserting at the last/end  // With tail pointer
    {
        Node* temp = new Node;
        temp->data = x;
        temp->next = nullptr;

        if(head == nullptr)
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

    void deleteStart()
    {
        Node* temp = head;
        head = temp->next;
        delete temp;
    }

    void deleteLast()
    {
        if(head = nullptr)
        {
            return;
        }
        else
        {
            Node* prev, *curr;
            curr = head;
            prev = head;

            while(curr != nullptr)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            delete curr;  // Removing the last node
            tail = prev;
        }
    }

    void deleteIndex(int index)
    {
        
    }


    void print()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

     ~LinkedList()  // Destructor to avoid memory leaks
    {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};