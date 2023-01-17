//link to solution: https://leetcode.com/problems/closest-prime-numbers-in-range/submissions/879948433/


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> v(right+1,true);
        v[1]= false;
        for(int i= 2;i*i<=right;i++){
            if(v[i]){
                for(int j=i*i;j<=right;j=j+i){
                    v[j]= false;
                }
            }
        }
        vector<int> prime;
        for(int i=left;i<=right;i++){
            if(v[i]){
                prime.push_back(i);
            }
        }
        int diff= INT_MAX;
        int lnumber=-1,rnumber=-1;
        if(prime.size()<2){
            return {-1,-1};
        }
        for(int i=0;i<prime.size()-1;i++){
            int tempdiff= prime[i+1]-prime[i];
            if(tempdiff<diff){
                diff= tempdiff;
                lnumber= prime[i];
                rnumber= prime[i+1];
            }
        }
        return {lnumber,rnumber};
    }
};
