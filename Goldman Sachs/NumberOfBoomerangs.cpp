//link to solution: https://leetcode.com/problems/number-of-boomerangs/submissions/872706609/


class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++){
                int dist= pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1], 2);
                mp[dist]++;
            }
            for(auto it: mp){
                if(it.second){
                    ans+= it.second*(it.second-1);
                }
            }
        }
        return ans;
    }
};
