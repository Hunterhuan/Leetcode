class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int cs[128] = {0}, ct[128] = {0};
        for(int i=0; i<s.size(); i++)
        {
            if(cs[s[i]] != ct[t[i]]) 
                return false;
            cs[s[i]] = i+1;
            ct[t[i]] = i+1;
        }
        return true;
    }
};