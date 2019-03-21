// 滑动窗口法
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 > len2) return false;

        vector<int> maps1(26), maps2(26);
        for (int i = 0; i < len1; ++i)
        {
            maps1[s1[i] - 'a'] ++;
            maps2[s2[i] - 'a'] ++;
        }
        if (maps1 == maps2) return true;

        for (int i = 0; i + len1 < len2; ++i)
        {
            maps2[s2[i] - 'a'] --;
            maps2[s2[i + len1] - 'a'] ++;
            if (maps1 == maps2) return true;
        }
        return false;

    }
};


// 用map来统计应该也可以。
// 但有个tips，以后用来统计固定范围的可以直接用线性表。比哈希表快。