class Solution {
public:
    int fun(int amount, vector<int>& coins, int n) {
        vector<vector<long long>> t(n + 1,
            vector<long long>(amount + 1, 0));

        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < amount + 1; j++) {
                if(i == 0)
                    t[i][j] = 0;
                else if(j == 0)
                    t[i][j] = 1;
            }
        }

        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < amount + 1; j++) {

                if(coins[i - 1] <= j) {
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];

                    if(t[i][j] > INT_MAX)
                        t[i][j] = INT_MAX;
                }
                else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return (int)t[n][amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return fun(amount, coins, n);
    }
};