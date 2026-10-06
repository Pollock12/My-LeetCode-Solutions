class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ans = 0;
        for (auto it : s) {
            if (it == '(')
                cnt++;
            else {
                if (cnt > 0) {
                    cnt--;
                } else {
                    ans++;
                }
            }
        }
        return cnt + ans;
    }
};