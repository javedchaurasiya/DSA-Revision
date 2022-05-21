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
    ListNode *detectCycle(ListNode *head) {
        node *fast=head,*slow=head;
        if(!head||!head->next)return NULL;
        
        while(fast)
        {
            fast=fast->next;
            if(fast)
            {
                fast=fast->next;
                slow=slow->next;
            }
            if(fast==slow)break;
        }
        if(!fast)return NULL;
        slow=head;
        
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow;
    }
};