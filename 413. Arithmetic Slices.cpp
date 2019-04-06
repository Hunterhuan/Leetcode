class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size();
        vector<int> dp(N+1,0);
        int sum = 0;
        for(int i=3;i<=N;++i){
            if(A[i-1]-A[i-2] == A[i-2]-A[i-3]){
                dp[i] = dp[i-1]+1;
                sum += dp[i];
            }
        }
        return sum;
    }
};

// 不用数组
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size();
        int last = 0;
        int sum = 0;
        for(int i=3;i<=N;++i){
            if(A[i-1]-A[i-2] == A[i-2]-A[i-3]){
                last = last+1;
                sum += last;
            }
            else
                last = 0;
        }
        return sum;
    }
};