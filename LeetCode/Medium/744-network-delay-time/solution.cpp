class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>a(n);
        for(int i=0;i<times.size();i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            a[s-1].push_back({d-1,w});
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        vector<int>dist(n, INT_MAX);
        dist[k-1] = 0;
        pq.push({0, k-1});
        while(!pq.empty()){
            pair<int, int>p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if(d>dist[node])
            continue;

            else
            for(int j=0;j<a[node].size();j++){
                int neigh = a[node][j].first;
                int wt = a[node][j].second;

                if(d+wt<dist[neigh]){
                    dist[neigh] = d+wt;
                    pq.push({d+wt, neigh});
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)
            return -1;
            ans = max(ans, dist[i]);
        }
        return ans;

    }
};