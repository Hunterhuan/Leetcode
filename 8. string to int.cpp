//string to int
// 这个之前就没写出来，应该可以考验代码的完备性
// 这个是copy的别人的代码

// 这个题关键要记住别人的完备性 和 如何处理字符串

class Solution {
public:
    int myAtoi(string str) {
        int i, ans, sign, backup;
        i=0;
        // 去除最前边的空格
        while(i<str.length() && str.at(i) == ' ')
            i++;
        sign = 1; // positive
        // 看有接着没有符号
        if(i<str.length() && str.at(i) == '+')
        {
            // 如果是 +
            i++;
        }
        else if(i<str.length() && str.at(i) == '-')
        {
            // 如果是 -
            sign = -1;
            i++;
        }
        // 然后开始转换为int
        ans=0;
        while(i<str.length() && isdigit(str.at(i)))
        {
            backup = ans;
            ans = ans*10+(str.at(i)-'0');
            // 如果越界，那么就直接最大值或最小值
            if(ans<0 || backup != (ans-(str.at(i)-'0'))/10)
                return sign==1?INT_MAX:INT_MIN;
            i++;
        }
        return ans*sign;
    }
};


class Solution {
public:
    int myAtoi(string str) {
        bool neg=false;
        int start=0;
        long ret=0;
        while (start < str.size()) {
            if (str[start] == ' ') start++;
            else break;
        }
        neg=str[start] == '-';
        if (str[start] == '-' || str[start] == '+') start++;
        while (isdigit(str[start])) {
            int digit=str[start] - '0';
            ret=ret*10 + digit;
            if (ret < INT_MIN || ret > INT_MAX) break;
            start++;
        }
        if (neg) ret*=-1;
        if (ret < INT_MIN) return INT_MIN;
        if (ret > INT_MAX) return INT_MAX;
        return (int) ret;
    }
};