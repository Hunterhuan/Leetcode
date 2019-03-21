class Solution {
public:
    bool founded(string s, string t){
        int b = 0;
        for(int i=0;i<s.size()&& b<t.size();++i){
            if(s[i]==t[b])
                ++b;
        }
        if(b==t.size())
            return true;
        return false;
        
    }
    string findLongestWord(string s, vector<string>& d) {
        int res = 0;
        int res_index = -1;
        string empty="";
        for(int i=0;i<d.size();++i){
            if(d[i].size()<res)
                continue;
            if(founded(s,d[i]) && d[i].size()>=res){
                if(d[i].size()==res && d[i]>d[res_index])
                    continue;
                res = d[i].size();
                res_index = i;
            }
        }
        if(res_index==-1)
            return empty;
        return d[res_index];
    }
};



// 别人的solution
// 简洁明了
string findLongestWord(string s, vector<string>& d) {
    string res = "";
    for(int i =0; i < d.size(); i++) {
        int one = 0;
        int two = 0;
        while(one < d[i].size() && two < s.length()) {
            if(s[two] == d[i][one]) {
                one++;
            }
            two++;
        }
        if(one == d[i].size() && res.length() <=  d[i].length()) {
            if(res == "" || res > d[i] || res.length() <  d[i].length()) res = d[i];
        }
    }
    return res;
}