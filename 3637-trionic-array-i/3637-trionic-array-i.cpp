class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                left = i;
            } else {
                break;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                right = i;
            } else {
                break;
            }
        }
        if (left == 0 || right == n - 1 || left >= right) {
            return false;
        }
        for (int i = left + 1; i <= right; i++) {
            if (nums[i - 1] <= nums[i]) {
                return false;
            }
        }
        return true;
    }
};