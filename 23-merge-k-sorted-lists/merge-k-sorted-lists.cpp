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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> minHeap;
            for(auto node : lists){
                while(node){
                    minHeap.push({node->val,node});
                    node = node->next;
                }
            }
        ListNode* temp1= new ListNode(-1);
        ListNode* temp2=temp1;

        while(!minHeap.empty()){
            ListNode* utha=minHeap.top().second;
            minHeap.pop();
            temp2->next=utha;
            temp2=temp2->next;
        }
        return temp1->next;                                                   
    }
};