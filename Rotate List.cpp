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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)return head;
        
        node *t=head;
        
        int size=0;
        while(t)
        {
            size++;
            t=t->next;
        }
        
        k=k%size;
        if(k==0)return head;
        node *pre=NULL,*cur=head,*last=NULL;
        t=head;
        
        int ct=1;
        
        //i have calculated the kth item from last like this way because the interviewer might give you the size of the list and ask to the problem in one pass.
        while(t)
        {
            if(!t->next)last=t;
            t=t->next;
            if(ct>k)
            {
                pre=cur;
                cur=cur->next;
            }
            ct++;
        }
        last->next=head;
        head=cur;
        pre->next=NULL;
        return head;
        
        
    }
};