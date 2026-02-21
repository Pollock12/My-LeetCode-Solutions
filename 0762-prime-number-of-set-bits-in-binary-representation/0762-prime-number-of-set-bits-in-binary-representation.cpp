class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int j = i, cnt = 0;
            while (j) {
                if (j % 2)
                    cnt++;
                j /= 2;
            }
            if (cnt == 2 || cnt == 3 || cnt == 5 || cnt == 7 || cnt == 11 ||
                cnt == 13 || cnt == 17 || cnt == 19)
                ans++;
        }
        return ans;
    }
};