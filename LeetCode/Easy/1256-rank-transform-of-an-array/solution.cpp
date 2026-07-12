class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int curRank = 1;

        for (int x : sorted) {
            
            if (!rank.count(x))
                rank[x] = curRank++;
        }

        vector<int> ans;
        ans.reserve(arr.size());

        for (int x : arr)
            ans.push_back(rank[x]);

        return ans;
    }
};