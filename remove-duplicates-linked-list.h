/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // If the list is empty or has only one element, return it
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->val == current->next->val)
            {
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // Free memory for the duplicate node
            } else
            {
                // Move to the next distinct element
                current = current->next;
            }
        }

        return head;
    }
};
