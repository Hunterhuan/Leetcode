// 方阵求和。以前见过这种方法。使用遍历，也算ac了。
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        int res = INT_MIN;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                for(int p=0;p<i;++p){
                    for(int l=0;l<j;++l){
                        int tmp = sum[i][j] + sum[p][l] - sum[p][j] - sum[i][l];
                        if(tmp <= k)
                            res = max(res, tmp);
                        if(tmp==k)
                            return k;
                    }
                }
            }
        }
        return res;
    }
};


// 之后看看别人的优化
// 效率很高。看一下别人的代码逻辑
// 看不懂诶。ε=(´ο｀*)))唉
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        int res=INT_MIN;
        for(int l=0;l<m;l++)
        {
            vector<int>sum(n,0);
            for(int r=l;r<m;r++)
            {
                for(int i=0;i<n;i++)
                    sum[i]+=matrix[i][r];
                set<int> s;
                s.insert(0);
                int cur_sum=0;
                // 复杂度的优化主要在这一步，利用set search比较快的特点。
                for(auto &row : sum){
                    cur_sum+=row;
                    auto it=s.lower_bound(cur_sum-k);
                    if(it!=s.end())
                        res=max(res,cur_sum-*it);
                    s.insert(cur_sum);
                }
            }
        }
        return res;
    }
};