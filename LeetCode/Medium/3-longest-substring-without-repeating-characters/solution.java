import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int low = 0, high = 0;
        HashMap<Character, Integer> f = new HashMap<>();
        int n = s.length();
        int res = 0;
        for (high = 0; high < n; high++) {
            char ch = s.charAt(high);
            f.put(ch, f.getOrDefault(ch, 0) + 1);
            while (f.size() < high - low + 1) {
                char left = s.charAt(low);
                f.put(left, f.get(left) - 1);
                if (f.get(left) == 0) {
                    f.remove(left);
                }
                low++;
            }
           int len = high - low + 1;
            res = Math.max(res, len);
        }
        return res;
    }
}