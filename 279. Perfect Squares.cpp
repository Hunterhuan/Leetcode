// solution1: dp
class Solution {
public:
    int numSquares(int n) {
        if(n==0)
            return 0;
        vector<int> dp(n+1,5);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i<=n;++i){
            for(int j=1;j<=i;++j){
                if(i-j*j<0)
                    break;
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};


// solution2: bfs
// 还是真的强，bfs，就是看哪个到树的最底部最近。
class Solution {
public:
    int numSquares(int n) {
        // bfs
        vector<bool> visited(n+1,0);
        vector<int> squarenum;
        for(int i=1;i*i<=n;i++){
            int j=i*i;
            if(j==n) return 1;
            squarenum.push_back(j);
            visited[j]=1;   
        }
        queue<int> bfs;
        for(int k:squarenum)
            bfs.push(k);
        int count=1;
        while(!bfs.empty()){
            count++;
            int sz=bfs.size();
            for(int j=0;j<sz;j++){
                int cur=bfs.front();
                for(int i=0;i<squarenum.size();i++){
                    int tmp=cur+squarenum[i];
                    if(tmp==n) return count;
                    if(tmp>n) break;
                    if(tmp<n&&(visited[tmp]==0)){
                        visited[tmp]=1;
                        bfs.push(tmp);
                    }   
                }
                bfs.pop();
            }
        }
        return 0;
    }
};

// solution3: math
class Solution {
public:
    int numSquares(int n) {
        // 直接开方的是1
        int temp=sqrt(n);
        if(temp*temp==n){
            return 1;
        }
        // 满足公式的就是4个的
        temp=n;
        while(temp&3==0){
            temp>>=2;
        }
        if(temp&7==7){
            return 4;
        }
        // 然后遍历找出答案为2的
        for(int i=1;i*i<n;i++){
            temp=n-i*i;
            int a=sqrt(temp);
            if(a*a==temp){
                return 2;
            }
        }
        // 最后的就是答案为3的
        return 3;
    }
};


// https://www.jianshu.com/p/2925f4d7511b