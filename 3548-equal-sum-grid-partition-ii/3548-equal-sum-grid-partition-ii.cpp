class Solution {
public:
    typedef long long ll;
    long long tot = 0;
    bool check(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long top = 0;
        unordered_set<ll> st;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                top += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long bottom = tot - top;
            long long dif = top - bottom;
            if (dif == 0)
                return true;
            if (dif == (ll)grid[0][0])
                return true;
            if (dif == (ll)grid[0][n - 1])
                return true;
            if (dif == (ll)grid[i][0])
                return true;
            if (i > 0 && n > 1 && st.count(dif))
                return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tot += grid[i][j];
            }
        }
        if (check(grid)) {
            return true;
        }
        reverse(begin(grid), end(grid));
        if (check(grid)) {
            return true;
        }
        vector<vector<int>> transport(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transport[j][i] = grid[i][j];
            }
        }
        if (check(transport)) {
            return true;
        }
        reverse(begin(transport), end(transport));
        if (check(transport)) {
            return true;
        }
        return false;
    }
};