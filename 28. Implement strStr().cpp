// 就是遍历而已
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        bool flag=true;
        if(haystack.length()<needle.length())
            return -1;
        for(int i=0;i<haystack.length()-needle.length()+1;++i)
        {
            flag=true;
            for(int j=0;j<needle.size();++j)
            {
                if(haystack[i+j]!=needle[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
};


// 别人写的简洁版本。
// 效率很高
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j;
        for (i = j = 0; i < haystack.size() && j < needle.size();) {
            if (haystack[i] == needle[j]) {
                ++i; ++j;
            } else {
                i -= j - 1; j = 0;
            }
        }
        return j != needle.size() ? -1 : i - j;
    }
};


// kmp 算法
class Solution {
public:
    void getNext(vector<int> &next, string &needle) {
        int i = 0, j = -1;
        next[i] = j;
        while (i < needle.length() - 1) {
            while (j != -1 && needle[i] != needle[j]) j = next[j];
            ++i; ++j;
            //特殊情况，这里即为优化之处。考虑下AAAAB, 防止4个A形成0123在匹配时多次迭代。
            if (needle[i] == needle[j]) next[i] = next[j]; 
            else next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (haystack.empty()) return needle.empty() ? 0 : -1;
        if (needle.empty()) return 0;
        vector<int> next(needle.length() + 1);
        getNext(next, needle);
        int i = 0, j = 0;
        while (i != haystack.length()) {
            while (j != -1 && haystack[i] != needle[j]) j = next[j];
            ++i; ++j;
            if (j == needle.length()) return i - j;
        }
        return -1;
    }
};