class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int globleMax = 0, curMax = 0, globleMin = 0, curMin = 0;
        for(auto x:A){
            curMax = max(x, x+curMax);
            curMin = min(x, x+curMin);
            globleMax = max(curMax, globleMax);
            globleMin = min(curMin, globleMin);
        }
        return globleMax > 0 ? max(globleMax, accumulate(A.begin(), A.end(), 0) - globleMin) : *max_element(A.begin(), A.end());
    }
};