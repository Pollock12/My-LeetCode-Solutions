class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (auto& i : nums) {
            int ok = -1;
            for (int j = 1; j <= i; j++) {
                if ((j | (j + 1)) == i) {
                    ok = j;
                    break;
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};