class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        bool allOdd = true;
        bool allEven = true;
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 0) {
                allOdd = false;
                minEven = min(minEven, num);
            } else {
                allEven = false;
                minOdd = min(minOdd, num);
            }
        }
        return allOdd || allEven || minEven > minOdd;
    }
};