class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> ans;
        while (n) {
            ans.push_back(n % 2);
            n /= 2;
        }
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] == ans[i - 1])
                return false;
        }
        return true;
    }
};