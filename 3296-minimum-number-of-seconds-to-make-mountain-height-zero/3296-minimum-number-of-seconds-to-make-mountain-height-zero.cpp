class Solution {
public:
    bool ok(int mountainHeight, vector<int>& workerTimes, long long mid) {
        int n = workerTimes.size();
        int tot = 0;
        for (int i = 0; i < n; i++) {
            long long p = sqrt(((2 * mid) / workerTimes[i]) + 0.25) - 0.5;
            tot += p;
            if(tot>=mountainHeight)return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1, high = 1e16;
        while (low < high) {
            long long mid = (low + high) >> 1;
            if (ok(mountainHeight, workerTimes, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};