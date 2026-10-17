class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i =1;i<=n/2;i++){
            string news = "";
            if(n%i==0){
                string s1 = s.substr(0,i);
                for(int j=1;j<=n/i;j++){
                     news = news + s1;
                }
                if(news == s)
                return true;
            }
        }
        return false;
    }
};