/*有N件物品和一个容量为V的背包。
第i件物品的费用是c[i]，价值是w[i]。
求解将哪些物品装入背包可使价值总和最大。
*/

/*基本思路：这道题特点是每种物品仅有一件，放或不放
用子问题 f[i][v] 表示前i件物品恰好放入一个容量为v的背包可以获得的最大价值
那么 f[i][v] = max{f[i-1][v], f[i-1][v-c[i]]+w[i]}
这个方程很重要，基本所有的背包问题都是由这个衍生出来的。
*/

/*将前i件物品放入容量为v的背包中”这个子问题，
若只考虑第i件物品的策略（放或不放），
那么就可以转化为一个只牵扯前i-1件物品的问题。
如果不放第i件物品，
那么问题就转化为“前i-1件物品放入容量为v的背包中”，
价值为f[i-1][v]；
如果放第i件物品，
那么问题就转化为“前i-1件物品放入剩下的容量为v-c[i]的背包中”，
此时能获得的最大价值就是f[i-1][v-c[i]]再加上通过放入第i件物品获得的价值w[i]
*/

class Solution {
public:
    int knackpack(int N,int V,  vector<int>& c, vector<int>&w) {
    	vector<vector<int>> f(N+1, vector<int>(V,0));
    	for(int i=0;i<N;++i){
    		for(int v =c[i] ;v<V && ;++v){
    			f[i+1][v] = max(f[i][v], f[i][v-c[i]]+w[i]);
    		}
    	}
    	return f[N][V-1];
    }
};


// 可以优化空间
class Solution {
public:
    int knackpack(int N,int V,  vector<int>& c, vector<int>&w) {
    	vector<int> f(V,0);
    	for(int i=0;i<N;++i){
    		for(int v =V-1 ;v>=c[i] && ;--v){
    			f[v] = max(f[v], f[v-c[i]]+w[i]);
    		}
    	}
    	return f[V-1];
    }
};

// 有两种，一种是要求正好装满，一种是求最大，不装满也行。
/*区别在于初始化
一个只让f[0] = 0,其他为-infinity
一个是全为0*/