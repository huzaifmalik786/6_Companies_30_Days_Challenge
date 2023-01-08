//link to solution: https://leetcode.com/problems/invalid-transactions/submissions/874273507/


class Solution {
public:
    vector<string> split(string s){
      string t="";
        vector<string> v;
        for(int i=0;i<s.length();i++){
            if(s[i]==','){
                v.push_back(t);
                t="";
            }
            else{
                t+=s[i];    
            } 
        }
        v.push_back(t);
        return v;
    }
    
    bool check(string s,string time,string city,map<string,vector<string>>mp){
        for(auto x:mp[s]){
                     vector<string>out=split(x);
                     int val1=stoi(out[1]);
                     int val2=stoi(time);
                     if(out[3]!=city and abs(val2-val1)<=60){
                        return true;
                     }
                 }
        return false;
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        map<string,vector<string>>mp;
        int n=transactions.size();
        vector<vector<string>>v(n,vector<string>(4));
        int c=0;
        for(auto x:transactions){
            vector<string> out=split(x);
            v[c]=out;
            mp[out[0]].emplace_back(x);
            c+=1;
        }
        for(int i=0;i<n;i++){
             if(stoi(v[i][2])>1000){
                 res.push_back(transactions[i]);
             }
             else{
                 if(check(v[i][0],v[i][1],v[i][3],mp)){
                     res.push_back(transactions[i]);
                 }
             }    
        }
     
        return res;
    }
};
