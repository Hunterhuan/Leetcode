// 照搬着写的，但结果好像错了。这个方法是bfs，但是是递归的形式
class Solution {
public:
    int M = 1000000007;
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(N+1,-1)));
        return findPaths(m,n,N,i,j,memo);
    }
    int findPaths(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& memo){
        if(i==m || j==n || i<0 || j<0)
            return 1;
        if(N==0)
            return 0;
        if(memo[i][j][N]>=0)
            return memo[i][j][N];
        memo[i][j][N] = ((findPaths(m,n,N-1,i-1,j,memo)+findPaths(m,n,N-1,i+1,j,memo))%m + (findPaths(m,n,N-1,i,j-1,memo)+findPaths(m,n,N-1,i,j+1,memo))%m)%m;
        return memo[i][j][N];
    }
};

// 使用dfs就行了
// 感觉可以用queue去实现
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<pair<pair<int,int>, int>> v;
        int mod = 1000000007;
        int ans =0;
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[i][j] = 1;
        
        int ref[m][n];
        memset(ref, 0, sizeof ref);
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(i==0) ref[i][j]++;
                if(j==0) ref[i][j]++;
                if(i==m-1) ref[i][j]++;
                if(j==n-1) ref[i][j]++;
            }

        for(int k=0; k<N; k++){
            
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    if(dp[i][j])
                        ans = (ans % mod + (dp[i][j] % mod*ref[i][j] % mod) % mod) % mod;

             
            v.clear();
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    if(dp[i][j]) {
                        v.push_back({{i,j},dp[i][j]});
                        dp[i][j] =0;
                    }
            
            if(N==k-1) break;

            for(int k=0; k<v.size(); k++){
                int i=v[k].first.first;
                int j = v[k].first.second;
                int d = v[k].second;
                if(i-1>=0) dp[i-1][j] = (dp[i-1][j] % mod + d % mod) % mod;
                if(j-1>=0) dp[i][j-1] = (dp[i][j-1] % mod + d % mod) % mod;
                if(i+1<m) dp[i+1][j] = (dp[i+1][j] % mod + d % mod) % mod;
                if(j+1<n) dp[i][j+1] = (dp[i][j+1] % mod + d % mod) % mod;
            }
        }

        return ans%mod;
    }
};