//link to solution: https://leetcode.com/problems/ipo/submissions/873925531/


class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        int n= profits.size();
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int> q;
        int i=0;
        while(i<n && k>0){
            if(w>=v[i].first){
                q.push(v[i++].second);
            }
            else{
                if(q.empty()){
                    return w;
                }
                w+=q.top();
                q.pop();
                k--;
            }
        }
        while(k>0 && !q.empty()){
            w+=q.top();
            q.pop();
            k--;
        }
        return w;
    }
};
