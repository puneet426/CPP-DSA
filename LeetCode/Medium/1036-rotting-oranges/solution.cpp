class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isvalid(int n, int m,int i,int j){
    if(i<0 or i>=n or j<0 or j>=m){
        return false;
    }
    return true;
    }

    int orangesRotting(vector<vector<int>>& a)
{
    int n = a.size();
    int m = a[0].size();
    queue<pair<int,int>>q;
    int fresh = 0;
    int time =0;
    int i,j;
    for(int i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==2){
                q.push({i,j});
                a[i][j] = -2;
            }
            else if(a[i][j]==1)
            fresh++;
        }
    }
    while(!q.empty() and fresh>0){
        time++;
        int s = q.size();
        while(s--){
            pair<int,int>p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            for(int k=0;k<4;k++){
                int row = r + x[k];
                int col = c + y[k];
                if(isvalid(n,m,row,col) and a[row][col]==1){
                    q.push({row,col});
                    a[row][col] = -2;
                    fresh--;
                }
            }
        }
    }
    if(fresh>0){
        return -1;
    }
    return time;
}
};