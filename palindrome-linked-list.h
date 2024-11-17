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
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        stack<int> s1;
        ListNode* slow = head;
        ListNode* fast = head;

        // Push the first half of the list into the stack
        while (fast != nullptr && fast->next != nullptr)
        {
            s1.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip the middle element for odd-sized lists
        if (fast != nullptr) 
        {
            slow = slow->next;
        }

        // Compare the second half with the stack
        while (slow != nullptr)
        {
            if (s1.top() != slow->val)
            {
                return false;
            }
            s1.pop();
            slow = slow->next;
        }

        return true;
    }
};