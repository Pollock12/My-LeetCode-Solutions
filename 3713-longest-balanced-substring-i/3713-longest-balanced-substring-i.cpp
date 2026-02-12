class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            map<char, int> mp;
            int count=0,maxCount=0;
            for (int j = i; j < n; j++) {
                if (mp[s[j]] == 0) {
                    count++;
                }
                mp[s[j]]++;
                maxCount=max(maxCount,mp[s[j]]);
                if(maxCount*count==j-i+1){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};