// easy,以后是不是要经常使用一下lower_bound(nums.begin(), nums.end(), target) 这个函数
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
        auto it = lower_bound(nums.begin(),nums.end(),target);
        return (it!=nums.end() && *it==target) ? it-nums.begin() : -1;
    }
};