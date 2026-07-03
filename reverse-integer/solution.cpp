class Solution {
public:
    int reverse(int x) {
        int max_int = 2147483647, min_int = -2147483648;
        int reversed_x = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (reversed_x > max_int / 10 || (reversed_x == max_int / 10 && pop > 7)) return 0;
            if (reversed_x < min_int / 10 || (reversed_x == min_int / 10 && pop < -8)) return 0;
            reversed_x = reversed_x * 10 + pop;
        }
        return reversed_x;
    }
};