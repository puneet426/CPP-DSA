class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool valid(int i,int j, int n , int m){
        if(i<0 or i>=n or j<0 or j>=m){
            return false;
        }
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>res(n);
        int i; 
        for(i=0;i<n;i++){
            vector<int>t(m,INT_MAX);
            res[i] = t;
        }
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;

        res[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            pair<int, pair<int,int>>p = pq.top();
            pq.pop();
            int dist = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if(dist>res[row][col])
            continue;

            for(int k=0;k<4;k++){
                int r = row + x[k];
                int c = col + y[k];
                if(!valid(r,c,n,m))
                continue;

            int absdiff = abs(a[row][col] - a[r][c]);
            int newwt = max(absdiff , dist);
            if(newwt<res[r][c]){
                res[r][c] = newwt;
                pq.push({newwt,{r,c}});
            }
            }
        }
        return res[n-1][m-1];
    }
};