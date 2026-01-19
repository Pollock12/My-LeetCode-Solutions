class Solution {
public:
    bool check(vector<vector<int>>& pre, int threshold, int i, int j, int k) {
        int sum = pre[i + k][j + k] - pre[i + k][j] - pre[i][j + k] + pre[i][j];
        return sum <= threshold;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> pre(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                pre[i][j] = mat[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] -
                            pre[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int k = 1; k <= min(row, col); k++) {
            for (int i = 0; i < row - k + 1; i++) {
                for (int j = 0; j < col - k + 1; j++) {
                    if (check(pre, threshold, i, j, k)) {
                        ans = max(ans, k);
                    }
                }
            }
        }
        return ans;
    }
};