class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for (int i = 0, j = height.size() - 1; i < height.size();) {
            ans = max(ans, min(height[i], height[j]) * (j - 1));
            if (height[j] > height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};