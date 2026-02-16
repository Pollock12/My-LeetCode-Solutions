class Solution {
public:
    int reverseBits(int n) {
        int ans=0,i=31;
        while(n){
          int rem=n%2;
          n/=2;
          ans+=(rem*pow(2,i));
          i--;
        }
        return ans;
    }
};