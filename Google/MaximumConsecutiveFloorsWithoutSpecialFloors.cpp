//link to solution: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/submissions/884444121/


class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n= special.size();
        sort(special.begin(), special.end());
        int ans = max(special[0]-bottom,top-special[n-1]);
        for(int i=1;i<n;i++){
            ans= max(ans, special[i]-special[i-1]-1);
        }
        return ans;
    }
};
