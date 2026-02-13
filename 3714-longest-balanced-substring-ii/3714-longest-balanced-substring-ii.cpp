class Solution {
public:
    int solve(string& s, char ch1, char ch2) {
        int sum = 0, maxi = 0;
        map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch1) {
                sum++;
            } else if (s[i] == ch2) {
                sum--;
            } else {
                mp.clear();
                mp[0] = i;
                sum = 0;
                continue;
            }
            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxi;
    }
    int longestBalanced(string s) {
        int n = s.size(), ans = 1, cnt = 1;

        // first case
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);

        // second case

        ans = max(ans, solve(s, 'a', 'b'));
        ans = max(ans, solve(s, 'b', 'c'));
        ans = max(ans, solve(s, 'a', 'c'));

        // third case
        map<char, int> mp;
        map<pair<int, int>, int> mk;
        mk[{0, 0}] = -1;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            int cnt1 = mp['a'] - mp['b'];
            int cnt2 = mp['a'] - mp['c'];
            if (mk.find({cnt1, cnt2}) == mk.end()) {
                mk[{cnt1, cnt2}] = i;
            } else {
                ans = max(ans, i - mk[{cnt1, cnt2}]);
            }
        }
        return ans;
    }
};