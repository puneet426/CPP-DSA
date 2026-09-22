class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();
        int p = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    if(i==0||grid[i-1][j]==0) p++; //up
                if(j==0||grid[i][j-1]==0) p++; //left
                if(i==rows-1||grid[i+1][j]==0) p++; //down;
                if(j==col-1||grid[i][j+1]==0) p++; //right;
                }
            }
        }
        return p;
    }
};