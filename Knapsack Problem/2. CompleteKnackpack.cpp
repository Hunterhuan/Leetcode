/*有N件物品和一个容量为V的背包。
每种物品都有无限件，
第i件物品的费用是c[i]，价值是w[i]。
求解将哪些物品装入背包可使价值总和最大。
*/

/*
类似于01背包。
只是策略是取0，取1，取2....
仍然可以写出转移方程
f[i][v] = max{f[i-1][v-k*c[i]]+k*w[i] | 0<=k*c[i]<=v}
但可以预见复杂度不是简单的常数 O(N*V)了，而是加上了k
*/

// 一个简单的小优化， c[i]<=c[j] && w[i]>=w[j] 
// 那么就可以去除j了，选择j不如选择i
// 但这个优化不能改善最差情况的复杂度，因为可能一件也去不掉
// 这个优化可以简单的O(N^2)实现。

/*
有一个高效的转发方法：
把第i物品拆成费用为c[i]*2^k，价值为w[i]*2^k的若干件物品。
*/


//但是我们有最优的O(VN) 算法
// 跟01背包的代码比只是v的遍历方向变了。
class Solution {
public:
    int knackpack(int N,int V,  vector<int>& c, vector<int>&w) {
        vector<int> f(V,0);
        for(int i=0;i<N;++i){
            for(int v =c[i] ;v<V ;++v){
                f[v] = max(f[v], f[v-c[i]]+w[i]);
            }
        }
        return f[V-1];
    }
};

// 普通算法
class Solution {
public:
    int knackpack(int N,int V,  vector<int>& c, vector<int>&w) {
        vector<vector<int>> f(N+1, vector<int>(V,0));
        for(int i=0;i<N;++i){
            for(int v =c[i] ;v<V ;++v){
                for(int k = 0;k<=v/c[i];++k)
                    f[i+1][v] = max(f[i+1][v], f[i][v-k*c[i]]+k*w[i]);
            }
        }
        return f[N][V-1];
    }
};