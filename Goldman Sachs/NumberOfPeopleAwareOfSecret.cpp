//link to solution: https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/874135618/


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> v(2001,0);
        v[1]=1;
        int mod= 1e9+7;
        for(int i=1;i<=n;i++){
            for(int j=i+delay;j<i+forget;j++){
                v[j]=(v[j]+v[i])%mod;
            }
        }
        long long int ans=0;
        int i=0;
        while(forget--){
            ans= (ans+v[n-i])%mod;
            i++;
        }
        return ans;
    }
};
