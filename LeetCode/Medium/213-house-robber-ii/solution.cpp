class Solution {
public:

    int fun(vector<int>& a, int n, int i, int free, vector<vector<int>>& dp)
    {
        if(i == n)
            return 0;
        if(dp[i][free] != -1)
            return dp[i][free];
        if(free == 0)
            return dp[i][free] = fun(a, n, i + 1, 1, dp);
        int rob = a[i] + fun(a, n, i + 1, 0, dp);
        int skip = fun(a, n, i + 1, 1, dp);
        return dp[i][free] = max(rob, skip);
    }
    int solve(vector<int>& a)
    {
        int n = a.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++)
        {
            vector<int> temp(2, -1);
            dp[i] = temp;
        }
        return fun(a, n, 0, 1, dp);
    }
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> first;
        vector<int> second;
        for(int i = 0; i < n - 1; i++)
            first.push_back(nums[i]);
        for(int i = 1; i < n; i++)
            second.push_back(nums[i]);
        int ans1 = solve(first);
        int ans2 = solve(second);
        return max(ans1, ans2);
    }
};