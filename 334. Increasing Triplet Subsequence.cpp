class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return false;
        vector<int> v(n, INT_MIN);
        v[n-1] = nums[n-1];
        for(int i=n-2;i>=0;--i){
            v[i] = max(v[i+1], nums[i+1]);
        }
        vector<int> v2(n, INT_MAX);
        v2[0] = nums[0];
        for(int i=1;i<n;++i){
            v2[i] = min(v2[i-1], nums[i-1]);
        }
        for(int i=1;i<n-1;++i){
            if(nums[i]<v[i] && nums[i]>v2[i])
                return true;
        }
        return false;
    }
};


// 这个只需要遍历一遍
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;

        for (auto e : nums) {
            if (e <= a) {
                a = e;
            } else if (e <= b) {
                b = e;
            } else {
                return true;
            }
        }
        return false;
    }
};