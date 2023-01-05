//link to solution: https://leetcode.com/problems/longest-happy-prefix/submissions/872159017/


class Solution {
public:
    string longestPrefix(string s) {
        int n= s.size();
        vector<int> v(n, 0);
        int i=0, j=1;
        while(j<n){
            if(s[i]==s[j]){
                v[j]=i+1;
                i++;
                j++;
            }
            else if(i){
                i=v[i-1];
            }
            else{
                j++;
            }
        }
        return s.substr(0, i);
    }
};
