//link to solution: https://leetcode.com/problems/maximum-points-in-an-archery-competition/submissions/873908608/


class Solution {
public:
    vector<int> ans;
    int target=0;

    void solve(int index, int numArrows, vector<int>& aliceArrows, int sum,vector<int>& res){
        if(index==-1 || numArrows<=0){
            if(sum>target){
                target=sum;
                if(numArrows>0){
                    res[0]+=numArrows;
                }
                ans= res;
            }
            return;
        }
        int req= aliceArrows[index]+1;
        if(req<=numArrows){
            res[index]= req;
            solve(index-1, numArrows-req, aliceArrows, sum+index,res);
            res[index]= 0;
        }
        solve(index-1, numArrows, aliceArrows, sum, res);
        return;
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(12,0);
        solve(11, numArrows, aliceArrows, 0,res);
        return ans;
    }
};
