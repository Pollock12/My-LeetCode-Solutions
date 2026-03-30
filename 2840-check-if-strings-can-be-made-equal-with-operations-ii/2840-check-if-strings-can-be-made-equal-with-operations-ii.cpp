class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        map<char, int> even1, odd1, even2, odd2;
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                odd1[s1[i]]++;
                odd2[s2[i]]++;
            } else {
                even1[s1[i]]++;
                even2[s2[i]]++;
            }
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (even1[ch] == even2[ch] && odd1[ch] == odd2[ch]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
