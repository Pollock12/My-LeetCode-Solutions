class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        set<string>st;
        for(int i=0;i<n-k+1;i++){
            string str=s.substr(i,k);
            st.insert(str);
        }
        if(st.size()==pow(2,k))return true;
        else return false;
    }
};