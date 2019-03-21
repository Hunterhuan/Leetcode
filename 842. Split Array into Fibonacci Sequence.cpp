// 一直在想和greedy 有什么关系。但好像也没什么关系。
// 思路应该就是回溯
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        // ret 是结果
        vector<int> ret;
        vector<int> path;
        dfs(ret, path, S, 0);
        return ret;
    }
    bool isFabo(vector<int>& path, int num){
        int n = path.size();
        return n<2 || (n >= 2 && num - path[n-1] == path[n-2]);
    }
    void dfs(vector<int>& ret, vector<int>& path, string& S, int start){
        // 如果ret不空，说明已经找到了结果。那么就return
        if(!ret.empty()) return;
        // ret 为空
        // 到尽头了。那么就看是不是满足大于3个的条件
        if(start == S.size()){
            if (path.size()>=3) ret = path;
            return;
        }
        long val = 0;
        for(int i = start; i<S.size(); i++){
            // 从start开始，看看能不能拼成斐波那契数列
            val = 10*val + S[i]-'0';
            // 不满足条件，拼不成
            if(val > INT_MAX) return;
            // 能拼成
            if(isFabo(path, (int)val)){
                // 把这个填进去
                path.push_back(val);
                // 然后从i开始继续找下一位数字
                dfs(ret, path, S, i+1);
                // 如果下一位找不到，那么再pop出来，继续找新的path
                path.pop_back();
            }
            if(val == 0) return;
        }
    }
};
// 但觉得这个里面还有挺多的多余的调用的，虽然一调用就直接return出来了。