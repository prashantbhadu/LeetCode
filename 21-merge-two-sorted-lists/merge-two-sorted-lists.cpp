class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(list1 && list2){
            if(list1->val<=list2->val){
                curr->next=list1;
                list1=list1->next;
                curr=curr->next;
            }
            else{
                curr->next=list2;
                list2=list2->next;
                curr=curr->next;
            }
        }
        if(list1==NULL){
            curr->next=list2;
        }
        else{
            curr->next=list1;
        }
        return dummy->next;
       
    }
};
