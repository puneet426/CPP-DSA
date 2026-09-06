class Solution {
    int dp[1001][1001], n, m;

    int go(int i, int j, string &s, string &t){
        if(j == m) return 1;
        if(i >= n) return 0;

        int &ret = dp[i][j];
        if(~ret) return ret;

        ret = go(i + 1, j, s, t);
        if(s[i] == t[j]) ret += go(i + 1, j + 1, s, t);

        return ret;
    }

public:
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();

        memset(dp, -1, sizeof(dp));
        return go(0, 0, s, t);
    }
};