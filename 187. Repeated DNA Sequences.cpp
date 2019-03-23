// 啊啊啊啊，这种题给我tip我都想不出来

// 把每个长度为10的都编码成一个数字，类似于hashtable，
// 然后保存下来，看有没有重复的就行了

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        int cur = 0;
        // 找到第一个
        for (int i = 0; i < 9; ++i) cur = cur << 3 | (s[i] & 7);
        // 滑动窗口。看看有没有存在的
        for (int i = 9; i < s.size(); ++i) {
            cur = ((cur & 0x7ffffff) << 3) | (s[i] & 7);
            if (st.count(cur)) res.insert(s.substr(i - 9, 10));
            else st.insert(cur);
        }
        // 把set变成 vector是这么变的
        return vector<string>(res.begin(), res.end());
    }
};