#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:
    ListNode* head;
    int size;
public:
    Solution()
    {
        head = nullptr;
        size = 0;
    }
    ListNode* deleteMiddle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        // Use two pointers to find the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // To track the node before the middle

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now 'slow' is pointing to the middle node, 'prev' is the node before it
        prev->next = slow->next;  // Remove the middle node by skipping it

        // Delete the middle node
        delete slow;

        return head;
    }
};