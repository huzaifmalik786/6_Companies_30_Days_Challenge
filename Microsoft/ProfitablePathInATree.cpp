//link to solution: https://leetcode.com/problems/most-profitable-path-in-a-tree/submissions/871763352/


class Solution {
public:
    vector<vector<int>> adj;
    vector<int> dis, parent;

void dfs1(int u, int p=0, int d=0){
    parent[u]=p;
    dis[u]=d;
    for(int v:adj[u]){
        if(v==p){
            continue;
        }
        dfs1(v,u,d+1);
    }
}

int dfs2(int u, vector<int>& amount, int p=0){
    int x= amount[u];
    int temp= INT_MIN;
    for(int v: adj[u]){
        if(v!=p){
            temp= max(temp, dfs2(v,amount,u));
        }
    }
    if(temp==INT_MIN){
        return x;
    }
    return x+temp;
}

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n= amount.size();
        adj.resize(n,vector<int>());
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dis.resize(n);
        parent.resize(n);
        dfs1(0);
        int curr=bob;
        int bdist= 0;
        while(curr!=0){
            if(dis[curr]>bdist){
                amount[curr]=0;
            }
            else if(dis[curr]==bdist){
                amount[curr] = amount[curr]/2;
            }
            curr= parent[curr];
            bdist++;
        }
        return dfs2(0, amount);
        
    }
};
