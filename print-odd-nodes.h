class Solution {
public:
    void printSkipTwo(ListNode* head) {
        ListNode* current = head;

        // Traverse the list
        while (current != nullptr) {
            // Print the current node
            cout << current->val << " ";

            // Skip two nodes
            if (current->next != nullptr) {
                current = current->next->next;
            } else {
                break; // Stop if there are no two nodes to skip
            }

            // After skipping two nodes, move to the next node if it exists
            if (current != nullptr) {
                current = current->next;
            }
        }

        cout << endl;
    }
};