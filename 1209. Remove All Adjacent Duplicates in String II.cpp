class Solution {
public:
    void add(stack<char> &s1, stack<int> &s2, char a, int b, int k){
        b = b%k;
        if(b==0)
            return;
        if(s1.size()>0 && s1.top()==a){
            b += s2.top();
            s2.pop();
            b = b%k;
            if(b!=0)
                s2.push(b);
            else
                s1.pop();
        }
        else{
            s1.push(a);
            s2.push(b);
        }
    }
    string removeDuplicates(string s, int k) {
        stack<char> s1;
        stack<int> s2;
        int start = 0, end = 0;
        while(end<s.size()){
            for(end = start;end<s.size();++end){
                if(s[end]==s[start])
                    continue;
                else
                    break;
            }
            add(s1, s2, s[start], end-start, k);
            start = end;
        }
        string res = "";
        while(!s1.empty()){
            int b = s2.top();
            char a = s1.top();
            s1.pop();
            s2.pop();
            string tmp(b,a);
            res = tmp+res;
        }
        return res;
    }
};


// 别人的思路好简单
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        st.push(make_pair('!', 0));
        for (int i = 0; i < s.length(); i++) {
            if (st.top().first == s[i]) {
                if (++st.top().second == k) st.pop();
            } else {
                st.push(make_pair(s[i], 1));
            }
        }
        string ans = "";
        while (!st.empty()) {
            pair<char, int> let = st.top();
            while (let.second-- > 0) ans += let.first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};