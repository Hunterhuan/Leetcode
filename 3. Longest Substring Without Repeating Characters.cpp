// 使用map和遍历来实现
// 关键在于掌握 map.count() 和 map.find() 等内置函数的用法

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int l = 0;
        int res = 0;
        for(int r = 0; r < s.size();++r){
            if(m.count(s[r])){
                l = max(m[s[r]]+1, l);
            }
            m[s[r]] = r;
            res = max(res, r-l + 1);
        }
        return res;
    }
};


// 别人给出一个好思路，因为都是256以内的，所以自己建一个vector，其实就是一个map了。而且效率更好。厉害。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);//此处的vector相当于一个哈希表
        int max_len = 0;
        int len = s.size();//string的size()方法和length()方法内部实现其实完全一样，只不过容器都有size()方法，此处是为了满足不同人的习惯
        int start = -1;//起始位置
        for(int i = 0; i < len; i++)
        {   //遇到重复出现的字符,则start的位置变成重复的那个字符之前出现的位置
            if(dict[s[i]] > start)
               start = dict[s[i]];//本来start应该为dict[s[i]]+1的，但后面计算长度时，还需在加个1，相当于i-start+1,所以1相当于抵消了
           max_len = max(max_len, i - start);//每次迭代长度都更新
           dict[s[i]] = i;
        }
        return max_len;
    }
};


// 还有一种dp的思路
class Solution {
public:
int lengthOfLongestSubstring(string str) {
    int max_len = 0;//最大值
    int cur_len = 0;//以当前位置的字符结尾的不含重复字符的字符串的最大长度，对应f(i)
    int pos[255] = {0};//记录字符上一次出现的位置
    memset(pos,-1,sizeof(pos));
    int len = str.size();
    for(int i = 0; i < len; i++)
    {
        int pre_index = pos[str[i]];
        if(pre_index < 0 || i - pre_index > cur_len)
            cur_len++;
        else
        {
            cur_len = i - pre_index;
        }
        pos[str[i]] = i;
        if(cur_len > max_len)
            max_len = cur_len;
    }
    return max_len;
    }
};