//link to solution: https://leetcode.com/problems/bulls-and-cows/submissions/871169947/


class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();     
        unordered_map<int,int> cg;
        unordered_map<int,int> cs;
        int c=0,b=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){b++;}
            else{
                cs[secret[i]-'0']++;
                cg[guess[i]-'0']++;
            }
        }
        for(int i=0;i<cg.size();i++){
            c+=min(cg[i], cs[i]);
        }
        return to_string(b)+'A'+to_string(c)+'B';
    }
};
