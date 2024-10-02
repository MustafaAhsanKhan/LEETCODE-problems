#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int d){
        next = nullptr;
        data = d;
    }
    /* data */
};
Node* get(Node* headA, Node* headB){
    Node* ptrA = headA;
    Node* ptrB = headB;
    if(ptrA->next == NULL || ptrB->next == NULL)
    {
        return NULL;
    }
    while(ptrA!=ptrB)
    {
        ptrA = (ptrA->next)? ptrA->next : headB;
        ptrB = (ptrB->next)? ptrB->next : headA;
    }
    return ptrA;
}
int main(){
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = new Node(8);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next= new Node(5);

    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = headA->next->next;
    
    Node* temp = get(headA, headB);
    if(temp){
        cout << temp->data;
    }else{
        cout << "ds";
    }
    // headA->next->next->next->next= new Node(4);
    // headA->next->next->next->next->next= new Node(4);
    

}
