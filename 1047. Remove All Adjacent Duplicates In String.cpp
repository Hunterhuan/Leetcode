class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for(int i=0;i<S.size();++i){
            if(s.empty() || S[i]!=s.top())
                s.push(S[i]);
            else
                s.pop();
        }
        string res;
        while(!s.empty()){
            res = s.top() + res;
            s.pop();
        }
        return res;
    }
};