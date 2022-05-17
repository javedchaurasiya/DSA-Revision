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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        node *c=head,*p=NULL,*t=head;
        int ct=1;
        if(!head)return head;
        
        while(t->next)
        {
            if(ct>=n)
            {
                p=c;
                c=c->next;
            }
            t=t->next;
            ct++;
        }
        if(!p)head=c->next;
        else
        {
            p->next=p->next->next;
        }
        return head;
        
    }
};