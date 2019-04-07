/*有N件物品和一个容量为(V,U)的背包。
第i件物品的费用是a[i]和b[i]，价值是w[i]。
求解将哪些物品装入背包可使价值总和最大。
二维01 背包问题
*/

/*费用加了一维，那么状态也加一维就行了，
设f[i][v][u] 是前i件物品付出两种代价分别为v和u时可获得的最大价值。
转移方程：
f[i][v][u] = max{f[i-1][v][u], f[i-1][v-a[i]][u-b[i]]+w[i]}
*/


/*当每件物品只能取一次时，v和u采用逆序的循环，反之则正序
多重背包的话就拆分物品就可以了。*/


class Solution {
public:
    int knackpack(int N,int V, int U, vector<int>& a, vector<int>& b, vector<int>& w) {
        vector<vector<int>> f(N+1, vector<int>(V,0));
        for(int i=0;i<N;++i){
            for(int v =V-1 ;v>=a[i] ;--v){
            	for(int u = U-1; u>=b[i];--u ){
            		f[i+1][v][u] = max(f[i][v][u], f[i][v-a[i]][u-b[i]]+w[i]);
            	}
            }
        }
        return f[N][V-1][U-1];
    }
};
/*
其他的就在这个基础上变形就可以了*/