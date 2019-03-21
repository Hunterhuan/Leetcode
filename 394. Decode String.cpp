// 一次AC，真爽
class Solution {
public:
    string decodeString(string s) {
        string res="";
        int i=0;
        for(int i=0;i<s.size();++i){
            if(isdigit(s[i])){
                int index = i;
                while(index<s.size()){
                    if(isdigit(s[index]))
                        ++index;
                    else
                        break;
                }
                int times = stoi(s.substr(i, index-i));
                int cnt = 0;
                i = index;
                while(index<s.size()){
                    if(s[index]=='[')
                        cnt++;
                    if(s[index]==']')
                        cnt--;
                    if(!cnt)
                        break;
                    ++index;
                }
                string tmp = decodeString(s.substr(i+1, index - i - 1));
                i = index;
                for(int j = 0;j<times;++j)
                    res += tmp;
            }
            else if(isalpha(s[i]))
                res += s[i];
        }
        return res;
    }
};