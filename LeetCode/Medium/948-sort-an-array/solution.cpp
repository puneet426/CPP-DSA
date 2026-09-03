class Solution {
public:
    void sort(vector<int>& v, int low, int high) {
        if(low >= high)
            return;
        int mid = low + (high - low) / 2;
        sort(v, low, mid);
        sort(v, mid + 1, high);
        merge(v, low, mid, high);
    }
    void merge(vector<int>& v, int low, int mid, int high) {
        vector<int> temp;
        int i = low;
        int j = mid + 1;
        while(i <= mid && j <= high) {
            if(v[i] <= v[j]) {
                temp.push_back(v[i]);
                i++;
            }
            else {
                temp.push_back(v[j]);
                j++;
            }
        }
        while(i <= mid) {
            temp.push_back(v[i]);
            i++;
        }
        while(j <= high) {
            temp.push_back(v[j]);
            j++;
        }
        for(int k = 0; k < temp.size(); k++) {
            v[low + k] = temp[k];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};