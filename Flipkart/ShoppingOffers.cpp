//link to solution: https://leetcode.com/problems/shopping-offers/submissions/879084428/


class Solution {
public:
    int ans= INT_MAX;
    void helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int n, int k){
        if(n==0){
            ans= min(ans,k);
        }
        if(k>ans){
            return;
        }
        int size= needs.size();
        for(int i=0;i<special.size();i++){
            int apply=true;
            int temp=0;
            for(int j=0;j<size;j++){
                if(needs[j]<special[i][j]){
                    apply= false;
                }
            }
            if(apply){
                for(int j=0;j<size;j++){
                    needs[j]-=special[i][j];
                    temp+=special[i][j];
                }
                helper(price,special,needs,n-temp,k+special[i].back());
                for(int j=0;j<size;j++){
                    needs[j]+=special[i][j];
                }
            }
        }
        for(int i=0;i<size;i++){
            k+=needs[i]*price[i];
        }
        ans= min(ans,k);
        return;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=0;
        for(auto i: needs){
            n+=i;
        }
        helper(price,special,needs,n,0);
        return ans;
    }
};
