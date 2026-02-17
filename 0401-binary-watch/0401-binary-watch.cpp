class Solution {
public:
    int solve(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ans += (1 << i);
            }
        }
        return ans;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < (1 << 10); i++) {
            int count = 0;
            string s = "0000000000";
            for (int j = 0; j < 10; j++) {
                if ((1 << j) & i) {
                    count++;
                    s[j] = '1';
                }
            }
            if (count == turnedOn) {
                int hours = solve(s.substr(0, 4));
                int min = solve(s.substr(4, 6));
                if (hours <= 11 && min <= 59) {
                    string time = to_string(hours);
                    time += ':';
                    if (min < 10) {
                        time += '0';
                    }
                    time += to_string(min);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};