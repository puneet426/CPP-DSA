class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> a;
        for(int i = 0; i < nums.size(); i++) {
            a.push_back({nums[i], i});
        }
        sort(a.begin(), a.end());

        int low = 0;
        int high = a.size() - 1;

        while(low < high) {
            int sum = a[low].first + a[high].first;
            if(sum > target) {
                high--;
            }
            else if(sum < target) {
                low++;
            }
            else {
                return {a[low].second, a[high].second};
            }
        }
        return {};
    }
};