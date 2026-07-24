class Solution {
public:
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
bool valid(int i,int j,int n , int m){
    if(i<0 or i>=n or j<0 or j>=m){
        return false;
    }
    return true;
}
    void dfs(vector<vector<int>>& image,int i, int j, int n,int m,int initialcolor, int newcolor, vector<vector<bool>>&vis){
        
        vis[i][j] = true;
        image[i][j] = newcolor;
         for(int k=0;k<4;k++){
            int nr = i + x[k];
            int nc = j + y[k];
            if(valid(nr,nc,n,m) and image[nr][nc] == initialcolor and vis[nr][nc]==0)
            dfs(image,nr,nc,n,m,initialcolor, newcolor,vis);
        }
        
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];
        
        if (initialColor == color)
        return image;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dfs(image, sr, sc, n, m,
            initialColor, color, vis);

        return image;
       
    }
};