class Solution {
public:
    void func(int u,vector<vector<int>> &adj,vector<bool> &vis){
        vis[u] = true;
        for(int v:adj[u]){
            if(vis[v]) continue;
            func(v,adj,vis);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &it:invocations){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<bool> vis(n,false);
        func(k,adj,vis);
        for(auto &it:invocations){
            int u = it[0];
            int v = it[1];
            if(vis[u]) continue;
            if(vis[v]){
                vector<int> ans;
                for(int i=0; i<n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};