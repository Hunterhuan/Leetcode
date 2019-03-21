// 自己使用递归还是效率挺高的。
class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0;
        int cnt = 0;
        for(int i=0;i<S.size();++i){
            int cur = i;
            while(i<S.size()){
                if(S[i]=='(')
                    ++cnt;
                else if(S[i]==')')
                    --cnt;
                i++;
                if(!cnt)
                    break;
            }
            if(i - cur==2)
                res++;
            else{
                string sub_s = S.substr(cur+1, i-cur-2);
                res += 2*scoreOfParentheses(sub_s);
            }
            i--;
        }
        return res;
    }
};





// 别人用stack的solution
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        for(int i = 0; i < S.size(); ++i){
            if(S[i] == '('){
                st.push(0);
            }else if(S[i] == ')' && st.top() == 0){
                st.pop();
                int tmp = 1;
                if(!st.empty() && st.top() != 0){
                    tmp += st.top();
                    st.pop();
                }
                st.push(tmp);
            }else{
                int tmp = 2 * st.top();
                st.pop();
                st.pop();
                if(!st.empty() && st.top() != 0){
                    tmp += st.top();
                    st.pop();
                }
                st.push(tmp);         
            }
        }
        
        return st.top();
    }
};