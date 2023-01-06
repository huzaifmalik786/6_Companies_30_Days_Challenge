//link to solution: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/submissions/872412758/


class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        // sort(numsDivide.begin(), numsDivide.end());
        int count=0;
        int common=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            common= __gcd(common, numsDivide[i]);
        }
        if(common<nums[0]){
            return -1;
        }
        for(int i=0;i<nums.size();i++){
            if(common%nums[i]==0){
                return count;
            }
            else{
                count++;
            }
        }
        return -1;
    }
};
