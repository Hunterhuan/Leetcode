// 最傻逼的方法。就是不断找“abc”，然后替换掉，看最后是否为空
class Solution {
public:
    bool isValid(string S) {
        int pos=S.find("abc");
        while(pos!=-1){
            S = S.replace(pos,3,"");
            pos = S.find("abc");
        }
        return S.size()==0;
    }
};


// 用stack的方法还是挺快的。效率高多了
class Solution {
public:
    bool isValid(string S) {
        if(S.size()==0 || S.size()%3)
            return false;
        stack<char> st;
        char tmp1, tmp2;
        for(int i=0;i<S.size();++i){
            if(S[i]=='c'){
                if(st.size()<2)
                    return false;
                tmp2 = st.top();
                st.pop();
                tmp1 = st.top();
                if(tmp2=='b' && tmp1=='a')
                    st.pop();
                else{
                    st.push(tmp2);
                    st.push(S[i]);
                }
            }
            else
                st.push(S[i]);
        }
        return st.empty();
    }
};