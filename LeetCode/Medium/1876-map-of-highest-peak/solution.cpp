class Solution {
public:
 int x[4] = {-1,1,0,0};
 int y[4] = {0,0,-1,1};

 bool isvalid(int i,int j, int n , int m){
    if(i<0 or i>=n or j<0 or j>=m){
        return false;
    }
    return true;
 }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for(int k=0;k<4;k++){
                int nrow = row + x[k];
                int ncol = col + y[k];
                if(isvalid(nrow,ncol,n,m) && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return dist;
    }
};