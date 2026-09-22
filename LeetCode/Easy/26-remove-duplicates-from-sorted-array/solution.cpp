class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j=1;int unique = 1;
        int n = nums.size();
        while(j<n){
        if(nums[j]==nums[j-1]){
            j++;
            continue;
        }
        nums[i+1] = nums[j];
        i++;
        unique++;
        j++;
        }
        return unique;
    }

};