class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        set<int> st;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                st.insert(grid[r][c]);
                if (st.size() > 3) {
                    st.erase(st.begin());
                }
                for (int side = 1; r - side >= 0 && r + side < row &&
                                   c - side >= 0 && c + side < col;
                     side++) {
                    int sum = 0;
                    for (int k = 0; k <= side - 1; k++) {
                        sum += grid[r - side + k][c + k];
                        sum += grid[r + k][c + side - k];
                        sum += grid[r + side - k][c - k];
                        sum += grid[r - k][c - side + k];
                    }
                    st.insert(sum);
                    if (st.size() > 3) {
                        st.erase(st.begin());
                    }
                }
            }
        }
        return vector<int>(st.rbegin(), st.rend());
    }
};