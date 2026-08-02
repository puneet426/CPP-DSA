class Solution {
public:
unordered_map<int, int>dp;
    int fib(int n) {
        if(n==0 or n==1){
            return n;
        } 
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        int a1 = fib(n-1);
        int a2 = fib(n-2);
        int ans = a1+ a2;
        dp[n] = ans;
        return ans;
    }
};