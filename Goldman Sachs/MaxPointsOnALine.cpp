//link to solution: https://leetcode.com/problems/max-points-on-a-line/submissions/873231780/


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2){
            return n;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            int temp=0;
            for(int j=i+1;j<n;j++){
                double x1 = points[i][0], y1 = points[i][1];
                double x2 = points[j][0], y2 = points[j][1];
                if(x2-x1==0){
                    mp[INT_MAX]++;
                    ans= max(ans,mp[INT_MAX]);
                }
                else{
                    double slope= (y2-y1)/(x2-x1);
                    mp[slope]++;
                    ans= max(ans, mp[slope]); 
                }
            }
        }
        return ans+1;
    }
};
