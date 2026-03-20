class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> ans;
        for (int r = 0; r < row - k + 1; r++) {
            vector<int> res;
            for (int c = 0; c < col - k + 1; c++) {
                set<int> s;
                for (int i = r; i < r + k; i++) {
                    for (int j = c; j < c + k; j++) {
                        s.insert(grid[i][j]);
                    }
                }
                if (s.size() == 1) {
                    res.push_back(0);
                } else {
                    vector<int> v(s.begin(), s.end());
                    int val = v[1] - v[0];
                    for (int z = 2; z < v.size(); z++) {
                        val = min(val, v[z] - v[z - 1]);
                    }
                    res.push_back(val);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};