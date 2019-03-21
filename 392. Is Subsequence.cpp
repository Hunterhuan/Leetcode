// 用的遍历法。效率不是很高

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        for(int i=0;i<t.size() && j<s.size();++i){
            if(t[i]==s[j])
                j++;
        }
        return j==s.size();
    }
};

// 感觉暂时没有想到其他更好的算法
