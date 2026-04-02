class Solution {
public:
    int m, n;
    int t[501][501][3];
    int goriberDP(int i, int j, vector<vector<int>>& coins, int neut) {
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && neut > 0) {
                return 0;
            }
            return coins[i][j];
        }
        if (i >= m || j >= n) {
            return INT_MIN;
        }

        if (t[i][j][neut] != INT_MIN) {
            return t[i][j][neut];
        }

        int take = coins[i][j] + max(goriberDP(i, j + 1, coins, neut),
                                     goriberDP(i + 1, j, coins, neut));
        int skip = INT_MIN;
        if (coins[i][j] < 0 && neut > 0) {
            int skipRight = goriberDP(i, j + 1, coins, neut - 1);
            int skipDown = goriberDP(i + 1, j, coins, neut - 1);
            skip = max(skipRight, skipDown);
        }
        return t[i][j][neut] = max(take, skip);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        int ans = goriberDP(0, 0, coins, 2);
        return ans;
    }
};