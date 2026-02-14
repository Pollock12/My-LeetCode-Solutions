class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev = {poured * 1.0};
        bool flag = false;
        while ((prev.size()) != query_row + 1) {
            vector<double> curr;
            flag = false;
            if (prev[0] > 1) {
                curr.push_back((prev[0] - 1) / 2);
                flag = true;
            } else {
                curr.push_back(0);
            }
            for (int i = 0; i < prev.size() - 1; i++) {
                double val = 0;
                if (prev[i] > 1) {
                    val += (prev[i] - 1) / 2;
                    flag = true;
                }
                if (prev[i + 1] > 1) {
                    val += (prev[i + 1] - 1) / 2;
                    flag = true;
                }
                curr.push_back(val);
            }
            if (prev.back() > 1) {
                curr.push_back((prev.back() - 1) / 2);
                flag = true;
            } else {
                curr.push_back(0);
            }
            prev = curr;
            if (!flag) {
                break;
            }
        }
        if (query_glass >= prev.size()) {
            return 0;
        } else {
            return min(prev[query_glass], 1.00);
        }
    }
};