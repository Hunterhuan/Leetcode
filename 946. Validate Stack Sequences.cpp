class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int cnt = 0;
        for(int i=0;i<pushed.size();++i){
            st.push(pushed[i]);
            while(!st.empty()){
                if(st.top()==popped[cnt]){
                    ++cnt;
                    st.pop();
                }
                else{
                    break;
                }
            }
        }
        return cnt==popped.size();
    }
};