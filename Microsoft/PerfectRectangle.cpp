//link to solution: https://leetcode.com/problems/perfect-rectangle/submissions/871413462/


class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>, int> mp;
        for(auto i: rectangles){
            mp[{i[0],i[1]}]++;
            mp[{i[2],i[3]}]++;
            mp[{i[0],i[3]}]--;
            mp[{i[2],i[1]}]--;
        }
        int c=0;
        for(auto i:mp){
            if(abs(i.second)==1){
                c++;
            }
            else if(i.second!=0){
                return false;
            }
        }
        return c==4;
    }
};
