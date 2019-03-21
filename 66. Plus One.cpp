//简单

#include <algorithm>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int tmp = 1;
        int a = 0;
        vector<int> res;
        for(int i=digits.size()-1;i>=0;--i){
            a = digits[i] + tmp;
            if(a<10)
                tmp = 0;
            else
                tmp = 1;
            res.push_back(a%10);
        }
        if(tmp==1)
            res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};