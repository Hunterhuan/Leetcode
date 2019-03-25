// 小写字母和大写字母在编码上不连续。
//大写+32变小写
class Solution {
public:
    void helper(vector<string> &res, string &S, int cur, string s){
        while(cur<S.size() && isdigit(S[cur])){
            s += S[cur];
            ++cur;
        }
        if(cur>=S.size()){
            res.push_back(s);
            return;
        }
        if(cur<S.size() && isalpha(S[cur])){
            helper(res, S, cur+1, s+S[cur]);
            helper(res, S, cur+1, s+char(S[cur]>='a' ? S[cur]-32:S[cur]+32));
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        helper(res, S, 0, "");
        return res;
    }
};