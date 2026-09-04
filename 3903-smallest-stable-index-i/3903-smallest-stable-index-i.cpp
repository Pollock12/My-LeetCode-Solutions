class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            int mn = nums[i];
            for (int j = i + 1; j < n; j++) {
                mn = min(mn, nums[j]);
            }
            if (mx - mn <= k) {
                return i;
            }
        }
        return -1;
    }
};