class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 2; i <= n; i++) {
            string sk = s;
            s += "1";
            for (int j = 0; j < sk.size(); j++) {
                if (sk[j] == '0')
                    sk[j] = '1';
                else
                    sk[j] = '0';
            }
            reverse(sk.begin(), sk.end());
            s += sk;
        }
        return s[k - 1];
    }
};