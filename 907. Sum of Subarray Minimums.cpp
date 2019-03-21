// 挺赞的一个题。本来想到一个一个边压入边弹出。
// 但没想到存储index
// too young, too naive
class Solution {
public:
    int sumSubarrayMins(vector<int> A) {
        int res=0;
        int mod = 1e9 + 7;
        stack<int> st;
        A.push_back(0);
        for(int i=0;i<A.size();++i){
            int cnt = 0;
            while(!st.empty() && A[st.top()] > A[i]){
                int j = st.top();
                st.pop();
                int k = st.empty() ? -1 : st.top();
                res = (res + A[j] * (j-k)*(i-j)) % mod;
            }
            st.push(i);
        }
        return res;
    }
};

