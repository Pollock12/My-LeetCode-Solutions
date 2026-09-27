class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> paranthesesIndices;
        string result;
        for (char ch : s) {
            if (ch == '(') {
                paranthesesIndices.push(result.length());
            } else if (ch == ')') {
                int start = paranthesesIndices.top();
                paranthesesIndices.pop();
                reverse(result.begin() + start, result.end());
            } else {
                result += ch;
            }
        }
        return result;
    }
};