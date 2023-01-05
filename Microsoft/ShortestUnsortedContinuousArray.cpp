//link to solution: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/872005465/


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v=nums;
        int n= nums.size();
        sort(v.begin(), v.end());
        if(nums==v){
            return 0;
        }
        int start=0, end= n-1;
        while(start<n && v[start]==nums[start]){
            start++;
        }
        while(end>0 && v[end]==nums[end]){
            end--;
        }
        return 1+(end-start);
    }
};
