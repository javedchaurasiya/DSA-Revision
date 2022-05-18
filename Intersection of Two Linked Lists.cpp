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
    
    int getSize(node *h)
    {
        if(!h)return 0;
        int size=0;
        node* t=h;
        while(t)
        {
            size++;
            t=t->next;
        }
        return size;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int a=getSize(headA),b=getSize(headB);
        if(a>b)return getIntersectionNode(headB,headA);
        int diff=b-a;
        
        while(diff--)headB=headB->next;
        
        while(headA)
        {
            if(headA==headB)return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
        
    }
};