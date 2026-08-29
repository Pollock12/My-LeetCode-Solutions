class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> vec;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        int pre = vec[0].first;
        int grp = 0;
        vector<vector<int>> keep(n + 1);
        map<int, int> mp;
        keep[0].push_back(pre);
        mp[vec[0].second] = 0;
        for (int i = 1; i < n; i++) {
            int rec = vec[i].first;
            if (rec - pre > limit) {
                grp++;
            }
            keep[grp].push_back(rec);
            mp[vec[i].second] = grp;
            pre = rec;
        }
        for (int i = 0; i <= grp; i++) {
            sort(keep[i].begin(), keep[i].end());
        }
        vector<int> ans(n);
        map<int, int> rec;
        for (int i = 0; i < n; i++) {
            int take = mp[i];
            ans[i] = keep[take][rec[take]];
            rec[take]++;
        }
        return ans;
    }
};