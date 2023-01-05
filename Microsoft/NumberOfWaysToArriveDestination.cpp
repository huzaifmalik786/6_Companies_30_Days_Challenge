//link to solution: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/submissions/872020356/


#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll, ll>> v[n];
        for(auto i: roads){
            v[i[0]].push_back({i[1],i[2]});
            v[i[1]].push_back({i[0],i[2]});
        }
        vector<ll> distance(n,LONG_MAX), ways(n,0);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        distance[0]=0;
        ways[0]=1;
        int mod= 1e9+7;
        while(!pq.empty()){
            ll dist= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            for(auto it: v[node]){
                int adj= it.first;
                ll weight= it.second; 
                if(weight+dist< distance[adj]){
                    distance[adj]= weight+ dist;
                    pq.push({weight+dist, adj});
                    ways[adj]= ways[node];
                }
                else if(weight+dist==distance[adj]){
                    ways[adj]= (ways[node]+ ways[adj])%mod;
                }
            }
        }
        return ways[n-1];
    }
};
