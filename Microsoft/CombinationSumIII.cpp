// Link to solution : https://leetcode.com/problems/combination-sum-iii/submissions/696905549/


class Solution {
    vector<vector<int>> ans;
public:
    
    int sum(vector<int> &comb){
        int a=0;
        for(auto x: comb){
            a+=x;
        }
        return a;
    }
    
    void helper(vector<int> &comb,int n,int k, int c){
        if(k==0){
            if(sum(comb)==n){
                ans.push_back(comb);
            }
            return;
        }
        if(c>9){return;}
        comb.push_back(c);
        helper(comb,n,k-1,c+1);
        comb.pop_back();
        helper(comb,n,k,c+1);
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n<k){
            return {};
        }
        vector<int> comb;
        helper(comb,n,k,1);
        return ans;
    }
};
