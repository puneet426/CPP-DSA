class Solution {
public:

    void dfs(vector<vector<int>>& adj, int node, vector<bool>& vis) {
        vis[node] = true;

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                dfs(adj, neigh, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> vis(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(adj, i, vis);
            }
        }
        return count;
    }
};