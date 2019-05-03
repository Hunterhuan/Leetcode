// 因为是固定了1-9， 所以是dfs，不断的搜索状态空间，找到所需的解。
class Solution {
public:

    vector<vector<int>> res;
    vector<int> ans;
    int sum;
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k == 0 || n == 0 ){
            return res;
        }

        if(k > n){
            return res;
        }
        //开始位置，已经用了几个数，当下几个数的和，k为元素个数
        dfs(1,0,n,k);
        return res;
    }
    //深度优先搜索
    void dfs(int start, int num, int n , int k){
        if(num == k){
            if(sum == n){
                res.push_back(ans);
            }
            return;
        }
        for(int i = start; i <= 9; i ++ ){
            sum += i;
            ans.push_back(i);
            if(sum <= n){
                dfs(++start,num+1,n,k);
            }
            ans.pop_back();
            sum -= i;
        }
    }
};