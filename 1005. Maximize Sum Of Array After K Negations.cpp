// 先sort，如果K够大把负的全变成正的。
// 如果K还够大，那么就把最小的正的来回变。就是变负再变正
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        
        sort(A.begin(), A.end());
        int minIdx = 0;
        // Do K steps
        for(int i = 0; i < K; i++){
            // change the sign of the smallest element
            A[minIdx] = -A[minIdx];
            if(minIdx == A.size()-1  || A[minIdx] > A[minIdx + 1])  minIdx++;
        }
        int sum = 0;
        for(auto a: A)  sum += a;
        return sum;
    }
};