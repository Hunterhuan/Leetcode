class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, visited[256] = {0};
        string res = "0";
        // 统计有词频
        for (auto a : s) ++m[a];
        for (auto a : s) {
            --m[a];
            if (visited[a])
                continue;
            // 如果res的最后一个比当前便利到的字母a大，而且res的最后一个在后面还存在的有，则删掉最后一个，把a补上
            while (a < res.back() && m[res.back()]) {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += a;
            // 表明a已经找到了最合适的位置
            visited[a] = 1;
        }
        return res.substr(1);
    }
};