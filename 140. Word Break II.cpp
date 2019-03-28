// 必须记录下来，不然就会Timelimit
class Solution {
public:
    void helper(string s, set<string>& dict, vector<vector<string>>& dp, vector<bool> &visited){
        int n = s.size();
        if(visited[n-1]==true)
            return;
        for(string w : dict){
            if(s==w){
                dp[n-1].push_back(w);
                continue;
            }
            int k = w.size();
            if(s.substr(0,k)==w){
                helper(s.substr(k,n),dict,dp,visited);
                for(auto str : dp[n-k-1])
                    dp[n-1].push_back(w+" "+str);
            }
        }
        visited[n-1] = true;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool> visited(s.size(),false);
        vector<vector<string>> dp(s.size());
        set<string> dict;
        for(string str : wordDict)
            dict.insert(str);
        helper(s, dict,dp, visited);
        return dp.back();
    }
};