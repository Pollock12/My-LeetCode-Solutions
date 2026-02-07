class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size(),st=-1,ed=-1,cnta=0,cntb=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                st=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                ed=i;
                break;
            }
        }
        if(st==-1 || ed==-1)return 0;
        for(int i=st;i<=ed;i++){
            if(s[i]=='a')cnta++;
            else cntb++;
        }
        int ans=min(cnta,cntb),skipb=0;
        for(int i=st;i<=ed;i++){
          if(s[i]=='b'){
            cntb--;
            if(min(cnta,cntb)==cnta){
               ans=min(ans,skipb+min(cnta,cntb)); 
            }
            else{
                ans=min(ans,1+skipb+min(cnta,cntb));
            }
            skipb++;
          }
          else{
            cnta--;
          }
        }
        return ans;
    }
};