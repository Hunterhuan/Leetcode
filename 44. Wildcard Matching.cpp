class Solution {
public:
    bool isMatch(string s, string p) {
        int pindex = 0, sindex = 0, sstart = 0, pstart = 0;
        while (sindex < s.size()) {
            if (p[pindex] == s[sindex] || p[pindex] == '?') {
                ++pindex;
                ++sindex;
            } else if (p[pindex] == '*') {
                pstart = ++pindex;
                sstart = sindex;
            } else if (pstart) {
                pindex = pstart;
                sindex = ++sstart;
            } else {
                return 0;
            }
        }
        while (pindex<p.size() && p[pindex]=='*') {
            ++pindex;
        }
        return pindex==p.size();
    }
};