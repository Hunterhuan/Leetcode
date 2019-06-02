class Solution {
public:
    bool check(string& a, string &b, int cnt){
        string sub = a.substr(0, cnt);
        string s1, s2;
        for(int i=1;i<a.size()/cnt;++i){
            s1 += sub;
        }
        if(s1!=a)
            return false;
        for(int i=1;i<b.size()/cnt;++i){
            s2 += sub;
        }
        if(s2!=b)
            return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int a = str1.size(), b = str2.size();
        if(a==0 || b==0)
            return "";
        int res = 0;
        for(int cnt=1;cnt<=min(a,b);++cnt){
            if(str1[cnt-1]!=str2[cnt-1])
                break;
            if(a%cnt!=0 || b%cnt!=0)
                continue;
            bool isok = check(str1, str2, cnt);
            res = cnt;
        }
        return str1.substr(0, res);
    }
};