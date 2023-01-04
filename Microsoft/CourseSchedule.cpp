//link to solution: https://leetcode.com/problems/course-schedule/submissions/871381581/


class Solution {
public:

    bool check(vector<int> adj[], vector<int>& visited, int i){
        if(visited[i]==1){
            return true;
        }
        if(visited[i]==0){
            visited[i]=1;
            for(auto it: adj[i]){
                if(check(adj, visited, it)){
                    return true;
                }
            }
        }
        visited[i]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> v(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(check(adj,v, i)){
                return false;
            }
        }
        return true;
        
    }
};
