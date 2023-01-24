//link to solution: https://leetcode.com/problems/maximum-good-people-based-on-statements/submissions/884432196/


class Solution {
public:
    int n=0;
    int ans=0;

    void dfs(vector<vector<int>>& st, string& s, int c, int i){
        if(i==n){
            if(check(st, s)){
                ans= max(ans,c);
            }
            return;
        }
        s.push_back('1');
        dfs(st, s, c+1, i+1);
        s.back()='0';
        dfs(st, s, c, i+1);
        s.pop_back();
    }

    bool check(vector<vector<int>>& st, string s){
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                for(int j=0;j<n;j++){
                    if(st[i][j]!=2 && st[i][j]!=s[j]-'0'){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    int maximumGood(vector<vector<int>>& statements) {
        string s= "";
        n=statements.size();
        dfs(statements, s, 0, 0);
        return ans;
    }
};
