// return的判断条件很难想明白
class Solution {
public:
    double soupServings(int N) {
        /**
               f(a,b) = { f(a-100,b) + f(a-75,b-25) + f(a-50,b-50) + f(a-25,b-75) } * 0.25
        **/
        return (N >= 5000) ? 1.0 : dfs(N, N);
    }
    
    double dfs(int a, int b) {
        if (a <= 0 && b >  0) return 1.0;
        if (a <= 0 && b <= 0) return 0.5;
        if (a >  0 && b <= 0) return 0.0;
        
        int key = a << 16 | b ;
        if (!dp.count(key)) dp[key] = ( dfs(a-100, b) + dfs(a-75, b-25) + dfs(a-50, b-50) + dfs(a-25, b-75) ) * 0.25;
        return dp[key];
    }
    
private:
    unordered_map<int,double> dp;
};