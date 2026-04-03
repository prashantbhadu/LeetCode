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
    ListNode* func(int val) {
        return new ListNode(val);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(l1!=NULL && l2!=NULL){
            int digit=0;
            digit=l1->val + l2->val+carry;
            carry=digit/10;
            
            digit=digit%10;
            ans->next=func(digit);
            ans = ans->next;

            l1 = l1->next;
            l2 = l2->next;
            
        }
        while(l1!=NULL){
            int digit=l1->val+carry;
            carry=digit/10;
            digit=digit%10;
            ans->next=func(digit);
            ans=ans->next;
            l1=l1->next;
        }
         while(l2!=NULL){
            int digit=l2->val+carry;
            carry=(digit/10>0)?1:0;
            digit=digit%10;
            ans->next=func(digit);
            ans=ans->next;
            l2=l2->next;
        }
        if(carry==1){
            ans->next=func(1);
        }
        return temp->next;
    }
};