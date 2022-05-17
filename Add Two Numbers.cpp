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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        node *ans=new node(-1),*t=ans;
        
        int c=0;
        
        while(l1||l2)
        {
            c+=(l1?l1->val:0)+(l2?l2->val:0);
            t->next=new node(c%10);
            c=c/10;
            t=t->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        
        if(c)t->next=new node(c);
        
        return ans->next;
    }
};