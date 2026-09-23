class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0, high = 0;
        unordered_map<char,int>f;
        int res = 0;
        for(high = 0;high<n;high++){
            f[s[high]]++;
            
            while(f.size()<high-low+1){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
            }
           int len = high-low+1;
            res = max(len,res);
        }
        return res;
    }
};