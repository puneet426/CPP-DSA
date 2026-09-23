class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int low = 0,high = 0;
        unordered_map<int,int>f;
        int res = INT_MIN;
        int n = arr.size();
        for(high = 0;high<n;high++){
            f[arr[high]]++;
            while(f.size()>2){
                f[arr[low]]--;
                if(f[arr[low]]==0){
                    f.erase(arr[low]);
                }
                low++;
            }
        int len = high - low + 1;
        res = max(res,len);
        }
        return res;
    }
};
