class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        long long int left = -100000;
        long long int right = 100000;

        int size = right - left + 1;
        vector<int>freq(size, 0);

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i] - left]++;
        }
        int ans = 0;
        int Residue = 0;
        for (int i = left; i <= right; i++) {
            ans += ((freq[i - left] + 1 - Residue) / 2) * i;
            Residue = (freq[i - left] + Residue) % 2;
        }

        return ans;
    }
};