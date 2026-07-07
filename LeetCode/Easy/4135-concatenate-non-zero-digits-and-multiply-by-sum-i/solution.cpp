class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        
        long long sum = 0;
        
        int divisor = 1;
        while (n / divisor >= 10) {
            divisor *= 10;
        }
        
        while (divisor > 0) {
            int digit = n / divisor;
            
            n %= divisor;
            
            if (digit != 0) {
                x = x * 10 + digit;
                
                sum += digit;
            }
            
            divisor /= 10;
        }
        
        return x * sum;
    }
};