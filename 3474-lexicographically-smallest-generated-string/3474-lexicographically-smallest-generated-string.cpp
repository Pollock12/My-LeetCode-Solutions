class Solution {
public:
    bool isSame(string& word, string& str2, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (word[i] != str2[j]) {
                return false;
            }
            i++;
        }
        return true;
    }
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string word(n + m - 1, '$');
        vector<bool> mark(n + m - 1, false);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int k = i;
                for (int j = 0; j < m; j++) {
                    if (word[k] != '$' && word[k] != str2[j]) {
                        return "";
                    }
                    word[k] = str2[j];
                    k++;
                    mark[j] = true;
                }
            }
        }
        for (int i = 0; i < m + n - 1; i++) {
            if (word[i] == '$') {
                word[i] = 'a';
                mark[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (isSame(word, str2, i, m)) {
                    bool change = false;
                    for (int k = i + m - 1; k >= i; k--) {
                        if (mark[k] == true) {
                            word[k] = 'b';
                            change = true;
                            break;
                        }
                    }
                    if (!change) {
                        return "";
                    }
                }
            }
        }
        return word;
    }
};