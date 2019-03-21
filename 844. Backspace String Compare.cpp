// 双指针法，自己写的除了bug，难受。别人的代码是真的简洁
class Solution {  
public:  
    bool backspaceCompare(string S, string T) {  
        return getS(S)==getS(T);  
    }  
         
    string getS(string& s) {  
        string a = "";  
        for (char c: s) {  
            if (c=='#'){  
                if (!a.empty()) a.pop_back();//a = a.substr(0, a.size()-1);  
            }  
            else a+=c;  
        }  
        return a;  
    }  
};  