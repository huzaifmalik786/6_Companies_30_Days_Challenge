//link to solution: https://leetcode.com/problems/count-nice-pairs-in-an-array/submissions/875394090/


class Solution {
public:

    int rev(int a){
        int ans=0;
        while(a>0){
            ans+=a%10;
            if(a/10){
                ans*=10;
            }
            a=a/10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        int mod= 1e9+7;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            nums[i]-= rev(nums[i]);
            if(mp.find(nums[i])!=mp.end()){
                ans+= mp[nums[i]]%mod;
                ans%=mod;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};
