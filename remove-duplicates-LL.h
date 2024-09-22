int func(Node* head)
{
    if (!head || !head->next)
        return 0;  // If the list is empty or has only one element, no duplicates

    Node* current = head;
    int count = 0;

    // Outer loop to iterate through each node
    while (current != nullptr)
    {
        Node* ahead = current->next;  // Compare current with all subsequent nodes
        bool duplicateFound = false;  // Track if we found a duplicate

        // Inner loop to compare the current node with all nodes ahead of it
        while (ahead != nullptr)
        {
            if (current->data == ahead->data)  // Duplicate found
            {
                duplicateFound = true;
                count++;
                break;  // Stop after finding the first duplicate for this node
            }
            ahead = ahead->next;
        }

        // Skip all duplicate nodes after the current node
        Node* temp = current->next;
        Node* prev = current;

        while (temp != nullptr)
        {
            if (temp->data == current->data)
            {
                // Skip the duplicate node
                prev->next = temp->next;
                delete temp;  // Free the memory of the duplicate node
                temp = prev->next;  // Move to the next node
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

        // Move to the next distinct node
        current = current->next;
    }

    return count;
}
