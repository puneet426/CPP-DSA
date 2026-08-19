class Solution {
public:
int t[1002][1002];
    int lcs(string &s, string &revs, int m, int n){
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0)
                t[i][j] = 0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==revs[j-1])
                t[i][j] = 1+ t[i-1][j-1];
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
    int minInsertions(string s) {
        int m = s.size();
        string revs = s;
        reverse(revs.begin(), revs.end());
        int n = m;
        int lps = lcs(s,revs,m,n);
        return m-lps;
    }
};