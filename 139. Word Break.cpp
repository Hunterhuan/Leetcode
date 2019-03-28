class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(string str : wordDict)
            dict.insert(str);
        int n = s.size();
        vector<bool> dp(n, false);
        for(int i = 0; i < n; ++i){
            for(string w : dict){
                int k = w.size();
                if(i-k+1 >= 0 && w == s.substr(i-k+1,k) && (i-k == -1 || dp[i-k]))
                    dp[i] = true;
            }
        }
        return dp[n-1];
    }
};