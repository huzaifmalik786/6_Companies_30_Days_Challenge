//link to solution: https://leetcode.com/problems/minimum-genetic-mutation/submissions/878771474/


class Solution {
public:

    int check(string &a, string &b){
        int x=0;
        for(int i=0;i<8;i++){
            if(a[i]!=b[i]){
                if(x){
                    return 0;
                }
                x=1;
            }
        }
        return x;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<int, string>> q;
        q.push({0,startGene});
        int len= bank.size();
        while(!q.empty()){
            pair<int, string> temp= q.front();
            q.pop();
            string s= temp.second;
            if(s==endGene){
                return temp.first;
            }
            for(int i=0;i<len;i++){
                if(check(bank[i],s)){
                    q.push({temp.first+1, bank[i]});
                    bank.erase(bank.begin()+i);
                    i--;
                    len--;
                }
            }
        }
        return -1;
    }
};
