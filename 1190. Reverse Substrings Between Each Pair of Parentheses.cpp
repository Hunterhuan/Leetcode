// 这个太妙了。
// 这个方法都不用考虑()reverse后需要变号。很难用言语表达
class Solution {
public:
    std::string reverseParentheses(std::string s) {
        int n=s.size();
        int begin=0, end=n-1;
        for(int i=0; i<n; i++){
            if(s[i] == '(')
                begin = i;
            if(s[i] == ')'){
                end = i;
                string temp = s.substr(begin + 1, end - begin - 1);
                reverse(temp.begin(),temp.end());
                return reverseParentheses(s.substr(0, begin) + temp + s.substr(end + 1));
             }
        }
        return s;
    }
};