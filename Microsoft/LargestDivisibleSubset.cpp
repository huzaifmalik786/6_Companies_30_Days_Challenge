//link to solution: https://leetcode.com/problems/largest-divisible-subset/submissions/871363791/


class Solution {
public:
    unordered_map<int,vector<int>> dp;

    vector<int> solve(vector<int>& nums, int i, int n){
        if(i>=n){
            return {};
        }
        if(dp.count(i)){
            return dp[i];
        }
        for(int j=i+1;j<n;j++){
            if(nums[j]%nums[i]==0){
                auto res= solve(nums, j, n);
                if(res.size()>= dp[i].size()){
                    dp[i]= res;
                }
            }
        }
        dp[i].push_back(nums[i]);
        return dp[i];
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            auto res = solve(nums, i, n);
            if(res.size()>ans.size()){
                ans= res;
            }
        }
        return ans;
    }
};
