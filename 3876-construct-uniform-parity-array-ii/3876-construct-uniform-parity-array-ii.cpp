class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = 1e9 + 7;
        for (auto it : nums1) {
            if (it % 2) {
                mn = min(mn, it);
            }
        }
        if (mn == 1e9 + 7)
            return true;
        for (auto it : nums1) {
            if (it % 2 == 0 && it < mn) {
                return false;
            }
        }
        return true;
    }
};