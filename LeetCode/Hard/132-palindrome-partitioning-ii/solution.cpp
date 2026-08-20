class Solution {
public:
    int t[2002];
    bool pal[2002][2002];
    int solve(string &s, int i, int n) {
        if (i == n)
            return 0;
        if (t[i] != -1)
            return t[i];
        int ans = INT_MAX;
        for (int j = i; j < n; j++) {
            if (pal[i][j]) {
                int temp = 1 + solve(s, j + 1, n);
                ans = min(ans, temp);
            }
        }
        return t[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        memset(pal, false, sizeof(pal));
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        return solve(s, 0, n) - 1;
    }
};