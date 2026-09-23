class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>f1;
        unordered_map<char,int> f2;
        int low = 0; int k = s1.size();int n = s2.size();
        if(k > n) return false;
        int high = k-1;
        for(int i=0;i<k;i++){
            f1[s1[i]]++;
        }
        for(int j=0;j<k;j++){
            f2[s2[j]]++;
        }
        while(high<n){
            if(f1==f2)
            return true;
            f2[s2[low]]--;
            if(f2[s2[low]] == 0) {
            f2.erase(s2[low]);
            }
            low++;
            high++;
            if(high < n) {
            f2[s2[high]]++;
            }
        }
        return false;
    }
};