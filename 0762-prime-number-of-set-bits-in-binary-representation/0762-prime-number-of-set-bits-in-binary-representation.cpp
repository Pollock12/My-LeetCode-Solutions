class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int j=i,cnt=0;
            while(j){
                if(j%2)cnt++;
                j/=2;
            }
            bool ok=true;
            for(int k=2;k<cnt;k++){
                if(cnt%k==0){
                    ok=false;
                    break;
                }
            }
            if(ok && cnt>1)ans++;
        }
        return ans;
    }
};