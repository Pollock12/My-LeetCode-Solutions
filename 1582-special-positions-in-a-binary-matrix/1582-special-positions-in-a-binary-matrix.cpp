class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0, col;
            for (int j = 0; j < m; j++) {
                sum += mat[i][j];
                if (mat[i][j] == 1) {
                    col = j;
                }
            }
            if (sum == 1) {
                int cnt2 = 0;
                for (int k = 0; k < n; k++) {
                    cnt2 += mat[k][col];
                }
                if (cnt2 == 1) {
                    cnt1++;
                }
            }
        }
        return cnt1;
    }
};