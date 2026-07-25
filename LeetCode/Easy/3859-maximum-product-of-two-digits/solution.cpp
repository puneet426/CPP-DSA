class Solution {
public:
    int maxProduct(int n) {
        int a = 0;
        int b = 0;

        while (n > 0) {
            int digit = n % 10;
            if (digit >= a) {
                b = a;
                a = digit;
            }
            else if (digit > b) {
                b = digit;
            }

            n /= 10;
        }

        return a * b;
    }
};