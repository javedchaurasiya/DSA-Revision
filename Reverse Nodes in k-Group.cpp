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
    
    bool check(node *head,int k)
    {
        node *t=head;
        int count=0;
        while(t)
        {
            count++;
            t=t->next;
            if(count>=k)break;
        }
        return count>=k;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!check(head,k))return head;
        
        int ct=0;
        node *cur=head,*pre=NULL,*next=NULL;
        
        while(cur)
        {
            if(ct==k)break;
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
            ct++;
        }
        if(next)head->next=reverseKGroup(next,k);
        return pre;
    }
};