// dfs
// 别人dfs都用栈实现的，挺不错的。
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> m;
        vector<string> res;
        if (tickets.size() <= 0) {
            return res;
        }
        for (pair<string, string> p: tickets) {
            m[p.first].insert(p.second);

        }
        stack<string> s;
        s.push("JFK");
        while (s.size()) {
            string next = s.top();
            if (m[next].empty()) {
                res.push_back(next);
                s.pop();
            } else {
                s.push(*m[next].begin());
                m[next].erase(m[next].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};