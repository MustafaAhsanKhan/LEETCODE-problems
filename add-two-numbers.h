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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        long long num1 = 0;
        long long num2 = 0;
        long long result = 0;

        // The logic is to go in order, unit, tenth, hundreth... so on
        // Traversing first LL
        long long multiplier = 1;
        while(l1)
        {
            num1 += (l1->val * multiplier);
            l1 = l1->next;
            multiplier = multiplier * 10;  // Next unit place
        }

        multiplier = 1;  // Resetting multiplier
        while(l2)
        {
            num2 += (l2->val * multiplier);
            l2 = l2->next;
            multiplier = multiplier * 10;  // Next unit place
        }

        result = num1 + num2;  // Here we have the answer

        if (result == 0)
        {
            return new ListNode(0);
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(result)
        {
            ListNode* newNode = new ListNode(result % 10);
            if (!head)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode; // Insert at end
                tail = tail->next;
            }
            result = result / 10;
        }

        return head;
    }
};