// 就是不够就补足。
class Solution {
public:
    int minAddToMakeValid(string S) {
        int count = 0;
        int res = 0;
        for(int i=0;i<S.size();++i){
            if(S[i]=='(')
                ++count;
            else if(S[i]==')')
                --count;
            if(count<0){
                count = 0;
                ++res;
            }
        }
        res += count;
        return res;
    }
};