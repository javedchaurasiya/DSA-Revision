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
#define  node ListNode
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        node *first=list1,*second=list2;
        node* head=new node(-1);
        node* t=head;
        while(first&&second)
        {
            if(first->val<second->val)
            {
                t->next=first;
                first=first->next;
            }
            else
            {
                t->next=second;
                second=second->next;
            }
            t=t->next;
        }
        if(first)t->next=first;
        else t->next=second;
        return head->next;
    }
};