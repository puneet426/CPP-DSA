class Solution {
public:
    using ll = long long;
    int n;
    ll solve(int i, int prevProd, int req, int k, auto& nums, auto& dp) {
        if(i >= nums.size()) return 0;
        if(dp[i][prevProd] != -1) return dp[i][prevProd];
        ll skip = 0, take = 0;
        if(prevProd == k){
            skip = solve(i + 1, k, req, k, nums, dp);
        }
        ll curProd;
        if(prevProd == k) curProd = nums[i]; 
        else curProd = (prevProd * nums[i]) % k; 

        take += (curProd == req);
        take += solve(i + 1, curProd, req, k, nums, dp);

        return dp[i][prevProd] = take + skip;
    }
    vector<ll> resultArray(vector<int>& nums, int k) {
        n = nums.size();
        vector<ll> res(k, 0);
        for(int& num : nums) num %= k;
        for(int r = 0; r < k; r++){
            vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));
            res[r] = solve(0, k, r, k, nums, dp);
        }
        return res;
    }
};