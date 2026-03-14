class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        queue<string> pq;
        pq.push("a");
        pq.push("b");
        pq.push("c");
        while (!pq.empty()) {
            string curr = pq.front();
            pq.pop();
            if (curr.size() == n) {
                ans.push_back(curr);
                continue;
            }
            string first = curr;
            string second = curr;
            if (curr.back() == 'a') {
                first += 'b';
                second += 'c';
            } else if (curr.back() == 'b') {
                first += 'a';
                second += 'c';
            } else {
                first += 'a';
                second += 'b';
            }
            pq.push(first);
            pq.push(second);
        }
        if (ans.size() < k)
            return "";
        else
            return ans[k - 1];
    }
};