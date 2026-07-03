class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low<high){
            int width = high-low;
            int h = min(height[high],height[low]);
            int area = width * h;
            ans = max(area,ans);
            if(height[low]<height[high])
            low++;
            else
            high--;
        }

        return ans;

    }
};