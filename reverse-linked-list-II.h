#include <iostream>
using namespace std;

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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* beforeLeft = nullptr;
        ListNode* leftNode = head;

        for(int i = 0; i < left - 1; ++i)
        {
            beforeLeft = leftNode;
            leftNode = leftNode->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = leftNode;
        ListNode* next = nullptr;

        for (int i = 0; i < right - left + 1; ++i)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        if (beforeLeft != nullptr)
        {
            beforeLeft->next = prev;
        }
        else
        {
            head = prev;
        }

        leftNode->next = curr;

        return head;
    }
};