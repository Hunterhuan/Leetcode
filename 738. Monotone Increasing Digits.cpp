class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i = 1;
        while(i<s.size() && s[i-1]<=s[i])
            ++i;
        while(i>0 && i<s.size() && s[i-1]>s[i])
            s[--i]--;
        for(int j=i+1; j<s.size();++j)
            s[j] = '9';
        return stoi(s);
    }
};
// 先从头找到持续增加的一段 eg: 34412 ‘345’12
// 然后在从5开始回溯，不断的减。见到都满足条件 '333'12
// 然后把后面的都置为9 '333'99