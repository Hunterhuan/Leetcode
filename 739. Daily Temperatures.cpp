// stack 的应用题，之前见过。这道就会做了。
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size()==0)
            return {};
        vector<int> res(int(T.size()), 0);
        map<int,int> m;
        stack<int> st;
        for(int i=T.size()-1;i>=0;--i){
            int last = 0;
            while(!st.empty()){
                if(st.top() > T[i]){
                    last = st.top();
                    break;
                }
                st.pop();
            }
            if(m[last])
                res[i] = m[last]-i;
            else
                res[i] = 0;
            m[T[i]] = i;
            st.push(T[i]);
        }
        return res;
    }
};