class Solution {
public:
int t[1002][1002];
    int lcs(string &s1, string &s2, int m, int n){
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0)
                t[i][j] = 0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1])
                t[i][j] = 1+t[i-1][j-1];
                else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[m][n];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        lcs(str1, str2, m, n);
        string ans = "";
        int i = m;
        int j = n;
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(t[i][j-1] > t[i-1][j]) {
                ans.push_back(str2[j-1]);
                j--;
            }
            else {
                ans.push_back(str1[i-1]);
                i--;
            }
        }
        while(i > 0) {
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j > 0) {
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};