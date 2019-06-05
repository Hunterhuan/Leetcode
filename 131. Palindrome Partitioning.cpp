class Solution {
private:
    bool judge(string &s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void helper(vector<vector<string>> &res, vector<string> cur, string s){
        if(s=="")
            res.push_back(cur);
        for(int i=1;i<=s.size();++i){
            string front = s.substr(0, i);
            if(!judge(front))
                continue;
            cur.push_back(front);
            helper(res, cur, s.substr(i));
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.size()==0)
            return res;
        vector<string> cur;
        helper(res, cur, s);
        return res;
    }
};