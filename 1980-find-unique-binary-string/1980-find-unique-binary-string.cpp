class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<string, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int n = nums.size();
        string ans;
        for (int mask = 0; mask < (1 << n); mask++) {
            string s = "";
            for (int i = n - 1; i >= 0; i--) {
                s += char(((mask >> i) & 1) + '0');
            }
            if (mp[s] == 0) {
                ans = s;
                break;
            }
        }
        return ans;
    }
};