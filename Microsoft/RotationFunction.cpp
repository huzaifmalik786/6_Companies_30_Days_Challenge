//Link to solution: https://leetcode.com/problems/rotate-function/submissions/871318591/


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n= nums.size();
        int sum=0,temp=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
            temp+=(nums[i]*i);
        }
        int ans=temp;
        for(int i=n-1;i>=0;i--){
            temp+= sum-(nums[i]*n);
            ans= max(ans, temp);
        }
        return ans;
    }
};
