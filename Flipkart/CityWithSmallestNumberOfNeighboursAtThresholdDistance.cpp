//link to solution: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/879906913/


class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    int dijkstra(int n, int i, int distanceThreshold){
        vector<int> distance(n,INT_MAX);
        priority_queue<pair<int,int>> pq;
        pq.push({0,i});
        distance[i]=0;
        while(!pq.empty()){
            auto [cost,node]= pq.top();
            pq.pop();
            for(auto it: adj[node]){
                int b= cost+it.second;
                int a= it.first;
                if(b<=distance[a]){
                    distance[a]= b;
                    pq.push({b,a});
                }
            }
        }
        int count=0;
        for(int j=0;j<n;j++){
            if(distance[j] <=distanceThreshold){
                count++;
            }
        }
        return count;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto i: edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        int result=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            int res= dijkstra(n,i,distanceThreshold);
            if(res<=result){
                result= res;
                ans=i;
            }
        }
        return ans;
    }
};
