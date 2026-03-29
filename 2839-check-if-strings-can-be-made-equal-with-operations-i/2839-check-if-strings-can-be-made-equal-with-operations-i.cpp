class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int i = 0; i < 4; i++) {
            if (s1[i] == s2[i])
                continue;
            else {
                if (i - 2 >= 0 && s2[i - 2] == s1[i]) {
                    continue;
                }
                if (i + 2 < 4 && s2[i + 2] == s1[i]) {
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};