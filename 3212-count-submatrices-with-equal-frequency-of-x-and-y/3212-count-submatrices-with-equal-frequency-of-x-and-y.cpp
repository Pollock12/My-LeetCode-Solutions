class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vec1(row, vector<int>(col, 0));
        vector<vector<bool>> vec2(row, vector<bool>(col, false));

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 'X') {
                    vec1[r][c] = 1;
                    vec2[r][c] = true;
                } else if (grid[r][c] == 'Y')
                    vec1[r][c] = -1;
                else
                    vec1[r][c] = 0;
            }
        }
        for (int r = 0; r < row; r++) {
            for (int c = 1; c < col; c++) {
                vec1[r][c] += vec1[r][c - 1];
                if (vec2[r][c - 1] == true) {
                    vec2[r][c] = true;
                }
            }
        }
        for (int r = 1; r < row; r++) {
            for (int c = 0; c < col; c++) {
                vec1[r][c] += vec1[r - 1][c];
                if (vec2[r - 1][c] == true) {
                    vec2[r][c] = true;
                }
            }
        }
        int cnt = 0;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (vec1[r][c] == 0 && vec2[r][c] == true) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};