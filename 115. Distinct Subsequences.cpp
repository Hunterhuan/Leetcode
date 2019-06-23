class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        
        vector<long> res(tlen+1, 0), temp(tlen+1, 0);
        
        
        res[0] = 1;
        temp[0] = 1;
        int ans = 0;
        for(int i=1; i<=slen; i++) {
            for(int j=1; j<=tlen; j++) {
                temp[j] = res[j];
                if(s[i-1] == t[j-1]) {
                    temp[j] += res[j-1];
                }
            }
            res = temp;
        }
        
        return res[tlen];
    }
};