/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define node ListNode
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        
        node *slow=head,*fast=head;
        while(fast)
        {
            fast=fast->next;
            if(!fast)return false;
            fast=fast->next;
            slow=slow->next;
            if(fast==slow)return true;
        }
        return false;
    }
};