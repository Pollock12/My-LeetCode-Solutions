class Solution {
public:
    int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0)), res(n,vector<int>(m,0));
        long long prod = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j]=prod;
                prod = (prod * grid[i][j]) % MOD;
            }
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] = (prefix[i][j] * prod) % MOD;
                prod = (prod * grid[i][j]) % MOD;
            }
        }
        return res;
    }
};