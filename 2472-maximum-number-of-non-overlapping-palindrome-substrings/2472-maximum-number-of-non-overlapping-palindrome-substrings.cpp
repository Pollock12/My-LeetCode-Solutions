class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), cnt = 0, start = 0;
        for (int j = k - 1; j < n; j++) {
            for (int i = start; i <= j - k + 1; i++) {
                int l = i, r = j;
                bool ok = true;
                while (l < r) {
                    if (s[l] != s[r]) {
                        ok = false;
                        break;
                    }
                    l++;
                    r--;
                }
                if (ok) {
                    cnt++;
                    start = j + 1;
                    break;
                }
            }
        }
        return cnt;
    }
};