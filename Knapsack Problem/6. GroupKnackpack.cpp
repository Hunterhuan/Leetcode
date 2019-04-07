/*有N件物品和一个容量为V的背包。第i件物品的费用是c[i],
价值w[i]。这些物品被划分为若干组，每组中的物品互相冲突，
最多选一件。
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。
*/

/*这个问题变成了每组物品都有若干种策略，是选择本组的某一件，还是一件都不选。
也就是说设f[k][v] 表示前k组物品花费费用v能取得的最大值
f[k][v] = max{f[k-1][v], f[k-1][v-c[i]]+w[i] | i属于k组}
*/


class Solution {
public:
    int knackpack(int N,int V, vector<vector<int>>& c, vector<vector<int>>& w) {
        int K = c.size();
        vector<vector<int>> f(K+1, vector<int>(V,0));
        for(int i=0;i<K;++i){
            for(int v =V-1 ;v>=a[i] ;--v){
            	f[i+1][v] = f[i][v];
            	for(int j=0;j<c[i].size();++j){
            		f[i+1][v] = max(f[i+1][v], f[i][v-c[i][j]]+w[i][j]);
            	}
            }
        }
        return f[K-1][V-1];
    }
};

// 还有一维复杂度的

class Solution {
public:
    int knackpack(int N,int V, vector<vector<int>>& c, vector<vector<int>>& w) {
        int K = c.size();
        vector<int> f(V,0);
        for(int i=0;i<K;++i){
            for(int v =V-1 ;v>=a[i] ;--v){
            	for(int j=0;j<c[i].size();++j){
            		f[v] = max(f[v], f[v-c[i][j]]+w[i][j]);
            	}
            }
        }
        return f[V-1];
    }
};