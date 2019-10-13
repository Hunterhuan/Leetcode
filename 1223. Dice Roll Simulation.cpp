// 以后遇见要剪枝的就要先向dp这边去想，然后结合dfs之类的。
// 试图写出dp状态转移方程，基本就成功了

class Solution {
    typedef long long LL;
    LL cache[5002][16][6];
    LL mod = 1000000000 + 7;
    vector<int> rollMax;
    LL dfs(int k, int index, int n){
        if(n == 0){
            return 1;
        }
        if(cache[n][k][index] != -1){
            return cache[n][k][index];
        }
        
        LL ans = 0;
        for(int i = 0; i < 6; i++){
            if(index != i){
                ans += dfs(1, i, n-1); //无关数字
            }else if(k < rollMax[i]){
                ans += dfs(k+1, i, n-1); //还没到达限制
            }else{
				//忽略
			}
        }
        return cache[n][k][index] = ans % mod;
    }
    
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        this->rollMax =  rollMax;
        LL ans = 0;
        memset(cache, -1, sizeof(cache));
        return dfs(0, 0, n); //这里把起始状态也当做依赖状态，不过这个依赖等价于没有依赖
    }
};