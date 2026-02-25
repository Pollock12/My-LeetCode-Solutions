class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans;
        for(auto it:arr){
            int f=it;
            int cnt=0;
            while(f){
                if(f&1)cnt++;
                f>>=1;
            }
            ans.push_back({cnt,it});
        }
        sort(ans.begin(),ans.end());
        vector<int>res;
        for(auto it:ans){
            res.push_back(it.second);
        }
        return res;
    }
};