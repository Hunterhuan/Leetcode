class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, left = -1, right = -1;
        for (int i = 0; i < A.size(); ++i) {
        	// 遇到了大于R的，则说明l要大于这个坐标
            if (A[i] > R) left = i;
            // 遇到了大于L的，则说明最大值已经满足条件了
            if (A[i] >= L) right = i;
            // 把满足条件的加上去
            res += right - left;
        }
        return res;
    }
};