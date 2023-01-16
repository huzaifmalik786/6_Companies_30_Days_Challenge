//link to solution: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/submissions/879066349/


class Solution {
public:
    int n;
    bool getksum(vector<int>& nums, vector<int>& visited,int target,int index,int currsum,int k){
        if(k==1){
            return true;
        }
        if(index>=n){
            return false;
        }
        if(currsum==target){
            return getksum(nums,visited,target,0,0,k-1);
        }
        for(int i=index;i<n;i++){
            if(visited[i] || currsum+nums[i]>target){
                continue;
            }
            visited[i]=1;
            if(getksum(nums,visited,target,i+1,currsum+nums[i],k)){
                return true;
            }
            visited[i]=0;
        }
        return false;     
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1){
            return true;
        }
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum%k!=0){
            return false;
        }
        n=nums.size();
        vector<int> visited(n,0);
        return getksum(nums, visited,sum/k,0,0,k);
    }
};
