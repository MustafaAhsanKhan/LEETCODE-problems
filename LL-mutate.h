struct Node
{
    char data;
    Node *next;
};
int Mutate(Node *head, char d)
{
    Node *ptr = head;
    bool check = false;
    Node *last_start = NULL, *last_end = NULL, *pre = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == d)
        {
            if (last_start)
            {
                Node *temp = last_start->next;
                last_start->next = last_end->next;
                pre->next = temp;
                last_end->next = ptr;
                last_start = pre;
            }
            last_start = pre;
            last_end = ptr;
            while (ptr->data == d)
            {
                last_end = ptr;
                ptr = ptr->next;
            }
        }
        pre = ptr;
        ptr = ptr->next;
    }
    Node *temp = last_start->next;
    last_start->next = last_end->next;
    pre->next = temp;
    last_end->next = ptr;
    last_start = pre;
    return 0;
}

// Train = A -> C -> B -> C -> C -> A -> D -> C -> C -> C -> B -> NULL
// What will be the resultant List train after passing Mutate(List, ‘C’);
// What is Time Complexity?