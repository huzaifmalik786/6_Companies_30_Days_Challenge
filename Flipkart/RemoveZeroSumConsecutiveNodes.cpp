//link to solution: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/submissions/879404449/


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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=new ListNode(0);
        temp->next= head;
        unordered_map<int,ListNode*> mp;
        mp[0]= temp;
        int sum=0;
        while(head!=NULL){
            sum+=head->val;
            if(mp.find(sum)!=mp.end()){
                ListNode* prev= mp[sum];
                ListNode* start= prev;
                int tempsum=sum;
                while(prev!=head){
                    prev= prev->next;
                    tempsum+= prev->val;
                    if(prev!=head){
                        mp.erase(tempsum);
                    }
                }
                start->next= head->next;
            }
            else{
                mp[sum]= head;
            }
            head= head->next;

        }
        return temp->next;
    }
};
