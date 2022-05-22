/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node *t=head;
        
        while(t)
        {
            Node *n=t->next;
            t->next=new Node(t->val);
            t->next->next=n;
            t=n;
        }
        t=head;
        while(t)
        {
            if(t->random)
            {
                t->next->random=t->random->next;
            }
            t=t->next->next;
        }
        t=head;
        Node *ans=new Node(-1),*x=ans;
        while(t)
        {
            x->next=t->next;
            x=x->next;
            t->next=t->next->next;
            t=t->next;
        }
        return ans->next;
        
    }
};