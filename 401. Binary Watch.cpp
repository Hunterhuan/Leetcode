// 自己还在想怎么实现排列组合的
// 看了别人的solution，发现别人是遍历了12*60
// 看看有多少个满足条件的就直接push_back到res里面

class Solution {
public:
    int countOneInBinary(int n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) count++;
            n = n >> 2;
        }
        return count;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> v;
        string time;
        for (int i = 0; i < 12; i++) {
            int oneInHour = countOneInBinary(i);
            for (int j = 0; j < 60; j++) {
                int oneInMin = countOneInBinary(j);
                if (oneInHour + oneInMin != num) {
                    continue;
                }
                else {
                    string h = to_string(i);
                    string m;
                    if (j < 10) {
                        m = "0" + to_string(j);
                    }
                    else {
                        m = to_string(j);
                    }
                    time = h + ":" + m;
                    v.push_back(time);
                }
            }
        }
        return v;
    }
};