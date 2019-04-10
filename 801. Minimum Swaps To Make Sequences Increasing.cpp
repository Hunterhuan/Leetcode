// 错误答案。自己的answer还是想错了
// 状态转移搞错了
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        if(N<=1)
            return 0;
        vector<int> dp(N+1,0);
        dp[0] = 0;
        bool swap = false;
        for(int i=1;i<N;++i){
            if(swap){
                if(A[i]>B[i-1] && B[i]>A[i-1]){
                    dp[i] = dp[i-1];
                    swap = false;
                }
                else{
                    dp[i] = dp[i-1] + 1;
                    swap = true;
                }
            }
            else{
                if(A[i]>A[i-1] && B[i] > B[i-1]){
                    dp[i] = dp[i-1];
                    swap = false;
                }
                else{
                    dp[i] = dp[i-1] + 1;
                    swap = true;
                }
            }
        }
        return min(dp[N-1], N-dp[N-1]);
    }
};


// 应该有两个状态，一个是i被换，一个是i不被换。然后让两个状态之间相互转移
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        if(N<=1)
            return 0;
        vector<int> dp_s(N+1,INT_MAX);
        vector<int> dp_nots(N+1,INT_MAX);
        dp_s[0] = 1;
        dp_nots[0] = 0;
        for(int i=1;i<N;++i){
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                dp_nots[i] = min(dp_nots[i-1], dp_nots[i]);
                dp_s[i] = min(1+dp_s[i-1], dp_s[i]);
            }
            if(A[i]>B[i-1] && B[i]>A[i-1]){
                dp_nots[i] = min(dp_s[i-1], dp_nots[i]);
                dp_s[i] = min(1+dp_nots[i-1], dp_s[i]);
            }
        }
        return min(dp_s[N-1], dp_nots[N-1]);
    }
};