// http://www.cnblogs.com/grandyang/p/4944875.html
// 这个blog给了比较详细的solution


// solution1: bfs
/*参考了网上大神的解法，这道题首先可以用BFS来解，
我们先把给定字符串排入队中，然后取出检测其是否合法，
若合法直接返回，
不合法的话，我们对其进行遍历，
对于遇到的左右括号的字符，我们去掉括号字符生成一个新的字符串，
如果这个字符串之前没有遇到过，将其排入队中，
我们用哈希集合记录一个字符串是否出现过。
我们对队列中的每个元素都进行相同的操作，
直到队列为空还没找到合法的字符串的话，那就返回空集，*/
class Solution {
public:
    // 能找到结果的关键在于后来进入队列的，都长度都是越来越短的。
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited{{s}};
        queue<string> q{{s}};
        bool found = false;
        while (!q.empty()) {
            // 找到队列第一个
            string t = q.front(); q.pop();
            // 如果是合法的，那么就放到res里面
            if (isValid(t)) {
                res.push_back(t);
                found = true;
            }
            // 如果找到了，那么就continue
            if (found) continue;
            // 没找到的情况下
            // 遍历每一个char
            for (int i = 0; i < t.size(); ++i) {
                //如果是字母，跳过
                if (t[i] != '(' && t[i] != ')') continue;
                // 如果不是，那么就把这个字母去掉。
                string str = t.substr(0, i) + t.substr(i + 1);
                // 然后放到队列里面去检查合理性
                if (!visited.count(str)) {
                    q.push(str);
                    visited.insert(str);
                }
            }
        }
        return res;
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            else if (t[i] == ')' && --cnt < 0) return false;
        }
        return cnt == 0;
    }
};




// 高票solution
// last_i 表示当前遍历到的位置。 last_j表示上一个删除的位置。这样可以避免重复计算

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s, 0, 0, {'(', ')'}, res);
        return res;
    }
    void helper(string s, int last_i, int last_j, vector<char> p, vector<string>& res) {
        int cnt = 0;
        for (int i = last_i; i < s.size(); ++i) {
            if (s[i] == p[0]) ++cnt;
            else if (s[i] == p[1]) --cnt;
            if (cnt >= 0) continue;
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == p[1] && (j == last_j || s[j] != s[j - 1])) {
                    helper(s.substr(0, j) + s.substr(j + 1), i, j, p, res);
                }
            }
            return;
        }
        string rev = string(s.rbegin(), s.rend());
        if (p[0] == '(') helper(rev, 0, 0, {')', '('}, res);
        else res.push_back(rev);
    }
};