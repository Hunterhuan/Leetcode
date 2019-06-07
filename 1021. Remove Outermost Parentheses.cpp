class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        size_t depth = 0;
        for (char& ch : S) {
            if (ch == '(') {
                if (depth > 0) {
                    result.push_back(ch);
                }
                ++depth;
            } else {
                --depth;
                if (depth > 0) {
                    result.push_back(ch);
                }
            }
        }
        
        return result;
    }
};