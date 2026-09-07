class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        const int mod = 1e9 + 7;

        vector<int> dp(n + 1);
        dp[0] = 1;
        vector<int> ch(26, -1);

        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            dp[i + 1] = dp[i] * 2 % mod;
            if (ch[x] >= 0)
                dp[i + 1] -= dp[ch[x]];
            dp[i + 1] %= mod;
            ch[x] = i;
        }
        dp[n]--;
        if (dp[n] < 0)
            dp[n] += mod;
        return dp[n];
    }
};