/*使用动态规划，不难，复杂度也不是很低。
dp[i] 就是以i结尾的子串最长的长度。*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if (words.empty()) return 0;
        int n = words.size(), result = 1;
        auto cmp = [](string & a, string& b) {
            return a.size() < b.size();
        };
        sort(words.begin(), words.end(), cmp);
        vector<int> dp(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPre(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
    
    bool isPre(string & a, string & b) {
        if (a.size() >= b.size()) return false;
        for (int i = 0; i < b.size(); i++) {
            if (a[i] != b[i]) return a.substr(i) == b.substr(i + 1);
        }
        return true;
    }
};