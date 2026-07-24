class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int node){
        vis[node] = true;
        for(int i=0;i<rooms[node].size();i++){
            int neigh = rooms[node][i];
            if(vis[neigh]==false){
                dfs(rooms,vis,neigh);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,0);
        dfs(rooms,vis,0);
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};