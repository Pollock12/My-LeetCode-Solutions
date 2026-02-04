class Solution {
public:
    typedef long long ll;
    vector<vector<ll>> dp;

    ll goriberDP(int i, int trend, int n, vector<int>& nums) {

        if (i == n) {
            if (trend == 3)
                return 0;
            else
                return LLONG_MIN / 2;
        }
        if (dp[i][trend] != LLONG_MIN) {
            return dp[i][trend];
        }
        ll take = LLONG_MIN / 2;
        ll skip = LLONG_MIN / 2;

        if (trend == 0) {
            skip = goriberDP(i + 1, trend, n, nums);
        }
        if (trend == 3) {
            take = nums[i];
        }

        if (i + 1 < n) {
            int curr = nums[i];
            int next = nums[i + 1];
            if (trend == 0 && next > curr) {
                take = max(take, curr + goriberDP(i + 1, trend + 1, n, nums));
            } else if (trend == 1) {
                if (next > curr) {
                    take = max(take, curr + goriberDP(i + 1, trend, n, nums));
                } else if (next < curr) {
                    take =
                        max(take, curr + goriberDP(i + 1, trend + 1, n, nums));
                }
            } else if (trend == 2) {
                if (next < curr) {
                    take = max(take, curr + goriberDP(i + 1, trend, n, nums));
                } else if (next > curr) {
                    take =
                        max(take, curr + goriberDP(i + 1, trend + 1, n, nums));
                }
            } else if (trend == 3 && next > curr) {
                take = max(take, curr + goriberDP(i + 1, trend, n, nums));
            }
        }

        return dp[i][trend] = max(take, skip);
    }
    ll maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1, vector<ll>(4, LLONG_MIN));
        return goriberDP(0, 0, n, nums);
    }
};