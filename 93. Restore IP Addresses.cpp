class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore(s, res, "", 0);
        return res;
    }

private:
    void restore(string s, vector<string>& res, string restored, int count) {
        if(count == 4) {
            if(!s.size()) {
                res.push_back(restored);
            }
            return ;
        }
        int n = s.size();
        for(int i = 1; i <= min(n, 4); i++) {
            string sub = s.substr(0, i);
            if(sub.size() > 1 && sub[0] == '0' || stoi(sub) > 255) break;
            string new_restore = restored + sub;
            if(count < 3) new_restore += '.';
            restore(s.substr(i), res, new_restore, count + 1);
        }
    }
};