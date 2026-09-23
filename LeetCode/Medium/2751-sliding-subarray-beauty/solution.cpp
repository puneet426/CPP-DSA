class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int low = 0;
        int high = k - 1;
        vector<int> res;
        unordered_map<int, int> f;
        for(int i = low; i <= high; i++) {
            if(nums[i] < 0) {
                f[nums[i]]++;
            }
        }
        while(high < n) {
            int count = 0;
            int ans = 0;
            for(int i = -50; i <= -1; i++) {
                count += f[i];
                if(count >= x) {
                    ans = i;
                    break;
                }
            }
            res.push_back(ans);
            if(nums[low] < 0) {
                f[nums[low]]--;
            }
            low++;
            high++;
            if(high < n && nums[high] < 0) {
                f[nums[high]]++;
            }
        }
        return res;
    }
};