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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode *t;
        //ListNode *head = t;
        ListNode *dummy = new ListNode(); //create dummy node to connect to sum-node
        ListNode *t = dummy;
        int c = 0;
        while(l1!=NULL && l2!=NULL){
            int s = l1->val + l2->val +c;
            c = s/10;
            t->next = new ListNode(s%10);
            l1 = l1->next;
            l2 = l2->next;
            t = t->next;
        }
        
        while(l1!=NULL){
            int s = l1->val +c;
            c = s/10;
            t->next = new ListNode(s%10);
            l1 = l1->next;
            t = t->next;
        }
        
        while(l2!=NULL){
            int s = l2->val +c;
            c = s/10;
            t->next = new ListNode(s%10);
            l2 = l2->next;
            t = t->next;
        }
        
        if(c!=0){
            t->next = new ListNode(c);
        }
        return dummy->next;
    }
};