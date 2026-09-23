import java.util.*;
class Solution {
    public int totalFruit(int[] fruits) {
        int low = 0, high = 0;
        int n = fruits.length;
        int res = Integer.MIN_VALUE;
        HashMap<Integer, Integer> f = new HashMap<>();
        for (high = 0; high < n; high++) {
            f.put(fruits[high], f.getOrDefault(fruits[high], 0) + 1);
            while (f.size() > 2) {
                f.put(fruits[low], f.get(fruits[low]) - 1);
                if (f.get(fruits[low]) == 0) {
                    f.remove(fruits[low]);
                }
                low++;
            }
            int len = high - low + 1;
            res = Math.max(res, len);
        }
        return res;
    }
}