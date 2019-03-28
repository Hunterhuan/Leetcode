// 不能忘了0和开头是0的状况
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(len==0 || s[0]=='0')
            return 0;
        vector<int> dp(len+1,0);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=len;++i){
            int tmp = (s[i-2]-'0')*10+(s[i-1]-'0');
            if(tmp>=10 && tmp<=26)
                dp[i] += dp[i-2];
            if(s[i-1]-'0'==0)
                continue;
            else{
                dp[i] += dp[i-1];
            }
        }
        return dp[len];
    }
};

// 别人使用 stoi
// 用两个数字代替dp数组
// 效率会高很多
class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if (length <= 0 || ('0' == s[0])) return 0;

        int prev_2 = 1;
        int prev_1 = 1;
        int cur = 1;
        for (int i = 1; i < length; i++) {
            cur = ('0' == s[i]) ? 0 : prev_1;
            if (isValid(s.substr(i - 1, 2))) {
                cur += prev_2;
            }
            prev_2 = prev_1;
            prev_1 = cur;
        }

        return cur;
    }

    bool isValid(string str) {
        int num = std::stoi(str);
        if (num >= 10 && num <= 26) {
            return true;
        }

        return false;
    }
};