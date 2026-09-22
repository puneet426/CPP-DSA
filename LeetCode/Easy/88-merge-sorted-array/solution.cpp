class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int low1 = 0; int low2 = 0; 
        while(low1<m and low2<n ){
            if(nums1[low1]<=nums2[low2]){
                ans.push_back(nums1[low1]);
                low1++;
            }
            else{
                ans.push_back(nums2[low2]);
                low2++;
            }
        }
        while(low2<n){
            ans.push_back(nums2[low2]);
            low2++;
        }
        while(low1<m){
            ans.push_back(nums1[low1]);
            low1++;
        }
        nums1 = ans;
    }
};