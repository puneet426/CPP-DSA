class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>>>a(n);
      for(int i=0;i<flights.size();i++){
        int s = flights[i][0];
        int d = flights[i][1];
        int price = flights[i][2];
        a[s].push_back({d,price});
      }  
      queue<pair<pair<int,int>,int>>q;
      vector<int>mincost(n,INT_MAX);
      mincost[src]  = 0;
      q.push({{0,src},0});   
      while(!q.empty()){
        pair<pair<int,int>,int>p = q.front();
        q.pop();
        int stops = p.first.first;
        int city = p.first.second;
        int cost = p.second;
        if(stops>k)
        continue;

        for(int j=0;j<a[city].size();j++){
            int nextcity = a[city][j].first;
            int price = a[city][j].second;

            if(cost+price<mincost[nextcity]){
                mincost[nextcity] = cost + price;
                q.push({{stops+1,nextcity},cost+price});
            }
        }
      }
      if(mincost[dst]==INT_MAX){
        return -1;
      }
      return mincost[dst];
    }
};