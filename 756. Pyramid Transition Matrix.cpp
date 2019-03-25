//dfs, 这个整个代码逻辑可以记一下。很多题都可以用一个模式套下来。
// 对map使用还是不够深入。应该想到用两个前缀作为key
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> hash;   // construct the hash map for acceleration
        for (auto &s : allowed) {
            hash[s.substr(0, 2)].push_back(s[2]);
        }
        string curr("");
        return DFS(bottom, curr, 0, hash);
    }
private:
    bool DFS(string &prev, string &curr, int k, unordered_map<string, vector<char>> &hash) {
        if (prev.length() == 1) {                   // the total pyramid has been constructed
            return true;
        }
        if (k + 1 == prev.length()) {               // the current layer has been constructed
            string next("");
            return DFS(curr, next, 0, hash);
        }
        else {
            string key = prev.substr(k, 2);
            if (hash.count(key) == 0) {             // no candidate
                return false;
            }
            else {                                  // try each candidate
                const vector<char> &chars = hash[key];
                for (int i = 0; i < chars.size(); ++i) {
                    curr.push_back(chars[i]);
                    if (DFS(prev, curr, k + 1, hash)) {
                        return true;
                    }
                    curr.pop_back();                // backtracking
                }
                return false;
            }
        }
    }
};