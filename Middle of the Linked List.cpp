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
#define node ListNode
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        node *fast=head,*slow=head;
        while(fast)
        {
            fast=fast->next;
            if(fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        return slow;
    }
};