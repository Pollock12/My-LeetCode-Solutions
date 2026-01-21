class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (auto it : nums) {
            if(it==2){
                ans.push_back(-1);
                continue;
            }
            int bit,ok=false;
            for(int i=0;i<=31;i++){
                if(it&(1<<i)){
                   bit=i;
                }
                else{
                   ok=true;
                   break;
                }
            }
            if(!ok){
                bit++;
            }
            int p=pow(2,bit);
            ans.push_back(it^p);
        }
        return ans;
    }
};