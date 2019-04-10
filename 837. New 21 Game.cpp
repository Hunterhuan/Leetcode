// 自己最开始写了遍历法。brute force，然后超时了。


// 看别人的solution

/*
W是区间
K<=N
*/

// (这个是逆向的)
// 正向的时候就是超出limit了
// 喜欢这个solution，容易理解
class Solution {
public:
double new21Game(int N, int K, int W) {
    if (K == 0 || N >= (K + W)) return 1.0;
    vector<double> dp(N + 1);
    double res = 0.0;
    double sum = 0.0;
    for (int i = 1; i <= N; i++) {
        dp[i] = i <= W ? sum / W + 1.0 / W : sum/W;  //如递推公式红色标出所示，两种的递推公式只有红色是不一样的，其余都是累加前面W项的和
        if (i < K) sum += dp[i];          //当i<k时min(k-1,i-1)=i-1，所以继续累加前面的和，当i>=k时min(k-1,i-1)=k-1，所以就不累加了
        if (i > W) sum -= dp[i - W];
        if (i >= K) res += dp[i];
    }
    return res;
}
};


class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> dp(N+W+1,0);
        for(int k=K; k<=N;++k)
            dp[k] = 1.0;
        double S = min(N-K+1, W);
        
        for(int k = K-1; k>=0; --k){
            dp[k] = S/W;

            S += dp[k] - dp[k+W];
        }
        return dp[0];
    }
};