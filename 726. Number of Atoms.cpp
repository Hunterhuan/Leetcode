// 这道题是hard， 但完全就是处理字符串的一道题。
// 关键就在于如何处理括号吧。还有map的用法。以及str如何判断大小写，如何判断数字，如何toint转换数字
class Solution {
public:
    string countOfAtoms(string formula) {
        string res = "";
        int pos = 0;
        map<string, int> m = parse(formula, pos);
        for (auto a : m) {
            res += a.first + (a.second == 1 ? "" : to_string(a.second));
        }
        return res;
    }
    map<string, int> parse(string& str, int& pos) {
        map<string, int> res;
        while (pos < str.size()) {
            if (str[pos] == '(') {
                ++pos;
                for (auto a : parse(str, pos))
                    res[a.first] += a.second;
            } else if (str[pos] == ')') {
                int i = ++pos;
                while (pos < str.size() && isdigit(str[pos])) ++pos;
                int multiple = stoi(str.substr(i, pos - i));
                for (auto a : res) res[a.first] *= multiple;
                return res;
            } else {
                int i = pos++;
                while (pos < str.size() && islower(str[pos]))
                    ++pos;
                string elem = str.substr(i, pos - i);
                i = pos;
                while (pos < str.size() && isdigit(str[pos])) 
                    ++pos;
                string cnt = str.substr(i, pos - i);
                res[elem] += cnt.empty() ? 1 : stoi(cnt);
            }
        }
        return res;
    }
};