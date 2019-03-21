// 这道题开始也没有思路，看了网上别人的solution才有思路，而且还看了好久才看懂。
// 它的cnt使用的很巧妙。很厉害
class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt = 0, i = 0;
        vector<string> v;
        string res = "";
        for (int j = 0; j < S.size(); ++j) {
            cnt += (S[j] == '1') ? 1 : -1;
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        for (int i = 0; i < v.size(); ++i) res += v[i];
        return res;
    }
};