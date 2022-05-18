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
    
    node* reverse(node *head)
    {
        node *cur=head,*pre=NULL,*next=NULL;
        
        while(cur)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(!head||!head->next)return true;
        node *slow=head,*fast=head,*pre=NULL;;
        
        while(fast)
        {
            fast=fast->next;
            if(fast)
            {
                pre=slow;
                slow=slow->next;
                fast=fast->next;
            }
        }
        pre->next=NULL;
        node *rev=reverse(slow);
        while(head&&rev)
        {
            if(head->val!=rev->val)return false;
            head=head->next;
            rev=rev->next;
        }
        return true;
    }
};