class Solution {
public:
    inline static bool isPal(int l, int r, string& s){
        for( ;l<r; l++, r--)
            if(s[l]!=s[r]) return 0;
        return 1;
    }
    static int maxPalindromes(string& s, int k) {
        const int n=s.size();
        int cnt=0, l0=0;
        for(int r=k-1; r<n; r++){
            int l=r-k+1;
            bool add=(l>=l0 && isPal(l, r, s))||(l>l0 && isPal(l-1, r, s));
            cnt+=add;
            l0+=(-add & r+1-l0);
        }
        return cnt;
    }
};