/*有N件物品和一个容量为V的背包。
i物品都有n[i]件可用，
第i件物品的费用是c[i]，价值是w[i]。
求解将哪些物品装入背包可使价值总和最大。
*/

/*
类似于完全背包问题，基本的方程只需要略改一下就可以了
策略是取0，取1，取2....
仍然可以写出转移方程
f[i][v] = max{f[i-1][v-k*c[i]]+k*w[i] | 0<=k*c[i]<=v & 0<=k<=n[i]}
但可以预见复杂度不是简单的常数 O(N*V)了，而是加上了k
*/

// 普通算法
// 转化为01背包
class Solution {
public:
    int knackpack(int N,int V,  vector<int>& n, vector<int>& c, vector<int>& w) {
        vector<vector<int>> f(N+1, vector<int>(V,0));
        for(int i=0;i<N;++i){
            for(int v =c[i] ;v<V ;++v){
                for(int k = 0;k<=v/c[i] && k<=n[i];++k)
                    f[i+1][v] = max(f[i+1][v], f[i][v-k*c[i]]+k*w[i]);
            }
        }
        return f[N][V-1];
    }
};

// 希望能够降低复杂度，那么就考虑二进制思想
/*我们考虑把第i种物品换成若干件物品，
使得原问题中第i种物品可取的每种策略
——取0..n[i]件——均能等价于取若干件代换以后的物品。
另外，取超过n[i]件的策略必不能出现*/

/*方法是：将第i种物品分成若干件物品，
其中每件物品有一个系数，这件物品的费用和价值均是原来的费用和价值乘以这个系数。
使这些系数分别为1,2,4,...,2^(k-1),n[i]-2^k+1，且k是满足n[i]-2^k+1>0的最大整数。
例如，如果n[i]为13，就将这种物品分成系数分别为1,2,4,6的四件物品。*/
// 这样就用01背包来解决。
class Solution {
public:
    int knackpack(int N,int V, vector<int>& n, vector<int>& c, vector<int>& w) {
        vector<int> f(V,0);
        vector<int> tmp_c, tmp_w;
        for(int i=0;i<N;++i){
            int i= 1;
            while(n[i]>=i){
                n[i] -= i;
                tmp_c.push_back(i*c[i]);
                tmp_w.push_back(i*w[i]);
                i = i<<1;
            }
            tmp_c.push_back(n[i]*c[i]);
            tmp_w.push_back(n[i]*w[i]);
        }
        for(int i=0;i<tmp_c.size();++i){
            for(int v =V-1 ;v>=c[i] ;--v){
                f[v] = max(f[v], f[v-tmp_c[i]]+tmp_w[i]);
            }
        }
        return f[V-1];
    }
};
