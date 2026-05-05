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
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt=1;
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }
        k=k%cnt;
        ListNode* dummy=head;
        cnt=cnt-k-1;
        while(cnt>0){
            dummy=dummy->next;
            cnt--;
        }
        temp->next=head;
        head=dummy->next;
        dummy->next=NULL;
        return head;

    }
};