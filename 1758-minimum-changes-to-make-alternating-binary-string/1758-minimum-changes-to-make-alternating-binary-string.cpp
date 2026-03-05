class Solution {
public:
    int minOperations(string s) {
        int cnt1=0,cnt2=0;
        char ch='0';
        for(auto st:s){
            if(st!=ch){
              cnt1++;
            }
            if(ch=='0')ch='1';
            else ch='0';
        }
        ch='1';
        for(auto st:s){
            if(st!=ch){
              cnt2++;
            }
            if(ch=='0')ch='1';
            else ch='0';
        }
        return min(cnt1,cnt2);
    }
};