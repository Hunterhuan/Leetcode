class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = 0;
        for(int i=0;i<k;++i)
            res += nums[i];
        double sum = res;
        res  = res/k;
        for(int i=1;i<nums.size()-k+1;++i){
            sum -= nums[i-1];
            sum += nums[i-1+k];
            res = max(res, sum/k);
        }
        return res;
    }
};