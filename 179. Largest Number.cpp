// 重点是如何构造比较函数。
// a+b > b+a
// 另外要记得如何写sort的自定义函数

class Solution {
public:
    static bool cmp(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        for(auto i:nums)
            str_nums.push_back(to_string(i));
        sort(str_nums.begin(), str_nums.end(), cmp);
        string res = "";
        for(auto a: str_nums)
            res += a;
        while(res[0] == '0' && res.length()>1)// 对特殊情况的处理
           res.erase(0,1);  //每次删除第一位的0，注意erase的用法
        return res;
    }
};