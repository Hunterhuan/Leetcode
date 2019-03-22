// 先sort， 变成有序数列，从小到大。
// 挺难理解的。先mark起来吧


class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        sort(A.begin(), A.end());
        int ans = A[n-1]-A[0];
        for(int i=0;i<n-1;++i){
            int a = A[i], b = A[i+1];
            int high = max(A[n-1]-K, a+K);
            int low = min(A[0]+K, b-K);
            ans = min(ans, high-low);
        }
        return ans;
    }
};



// 自己写的，写错了。
// 错误答案。自己理所当然认为值偏下的就应该加，偏上的就应该减。
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int max_num = INT_MIN;
        int min_num = INT_MAX;
        for(int i=0;i<A.size();++i){
            max_num = max(max_num, A[i]);
            min_num = min(min_num, A[i]);
        }
        int res_max = INT_MIN;
        int res_min = INT_MAX;
        for(int i=0;i<A.size();++i){
            if((max_num+min_num) >= (A[i]<<1)){
                A[i] += K;
            }
            else
                A[i] -= K;
        }
        for(int i=0;i<A.size();++i){
            res_max = max(res_max, A[i]);
            res_min = min(res_min, A[i]);
        }
        return res_max-res_min;
    }
};