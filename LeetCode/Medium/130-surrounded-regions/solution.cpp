class Solution {
public:
bool valid(int i,int j, int n, int m){
    if(i<0 or i>=n or j<0 or j>=m){
        return false;
    }
    return true;
}
int x[4] = {1,-1,0,0};
int y[4] = {0,0,1,-1};

    void dfs(vector<vector<char>>& a, int n , int m , int i, int j){
        a[i][j] = '#';
        for(int k=0;k<4;k++){
            int row = i+ x[k];
            int col = j+ y[k];
            if(valid(row,col,n,m) and a[row][col]=='O')
            dfs(a,n,m,row,col);
        }
        return;
    }

    void solve(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        int i,j;
        for(j=0;j<m;j++){
            if(a[0][j]=='O'){
                dfs(a,n,m,0,j);
            }
        }
        for(j=0;j<m;j++){
            if(a[n-1][j]=='O')
            dfs(a,n,m,n-1,j);
        }
        for(i=0;i<n;i++){
            if(a[i][0]=='O')
            dfs(a,n,m,i,0);
        }
        for(i=0;i<n;i++){
            if(a[i][m-1]=='O')
            dfs(a,n,m,i,m-1);
        }
        for(int i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]=='#')
                a[i][j]='O';
                else
                a[i][j]='X';
            }
        }
           return;
    }
 
};