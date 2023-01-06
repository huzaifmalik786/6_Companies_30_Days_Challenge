//link to solution: https://leetcode.com/problems/split-array-into-consecutive-subsequences/submissions/777492431/


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        unordered_map<int,int> need;
        for(int i: nums){
            if(mp[i]==0){
                continue;
            }
            else if(need[i]>0){
                mp[i]--;
                need[i]--;
                need[i+1]++;
            }
            else if(mp[i]>0 && mp[i+1]>0 && mp[i+2]>0){
                mp[i]--;
                mp[i+1]--;
                mp[i+2]--;
                need[i+3]++;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};
