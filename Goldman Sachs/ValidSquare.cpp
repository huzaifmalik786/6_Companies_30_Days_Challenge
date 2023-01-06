//link to solution: https://leetcode.com/problems/valid-square/submissions/872645251/


class Solution {
public:

    int distance(vector<int>& a, vector<int>& b){
        return (b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int s1= distance(p1,p3);
        int s2= distance(p1,p4);
        int s3= distance(p2,p3);
        int s4= distance(p2,p4);
        int d1= distance(p1,p2);
        int d2= distance(p3,p4);
        unordered_set<int> s;
        s.insert({s1,s2,s3,s4,d1,d2});
        return !s.count(0) && s.size()==2;
    }
};
