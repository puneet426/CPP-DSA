class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>f;
        int low = 0,high = 9;
        int n = s.size();
        while(high<n){
            string temp = s.substr(low,10);
            f[temp]++;
            if(f[temp]==2){
            ans.push_back(temp);
        }
            low++;
            high++;
        }
        return ans;
    }
};