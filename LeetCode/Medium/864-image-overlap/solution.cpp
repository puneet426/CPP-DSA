class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    
            int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
      
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c] == 1)
                    ones1.push_back({r, c});

                if (img2[r][c] == 1)
                    ones2.push_back({r, c});
            }
        }

        unordered_map<string, int> freq;
        int ans = 0;
        
        for (auto [r1, c1] : ones1) {
            for (auto [r2, c2] : ones2) {
                int dr = r2 - r1;
                int dc = c2 - c1;
                string key = to_string(dr) + "," + to_string(dc);
                ans = max(ans, ++freq[key]);
            }
        }
        return ans;
    }
};