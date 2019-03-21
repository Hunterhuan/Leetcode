// 这个要用到双指针法，双指针法也是要突破的一个内容。要求掌握。

//解题思路：采用滑动窗口算法(Slide Window Algorithm)。

//设下标 l 和 r, 把左开右闭 [l, r) 想象成一个窗口。

// 当窗口内的和 sum 小于 s 时， 则 r 向右滑动，增加窗口区间。
// 当窗口内的和 sum 大于等于 s 时，表示已经满足原题目要求，是一个可行解，解 l 向右滑动，继续求解。

// 移动窗口，第一次看到。感觉跟双指针类似
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int max_size = nums.size();
        if(max_size==0)
            return 0;
        int l = 0, r = 0;
        int sum = 0;
        int res = INT_MAX;
        while(r < nums.size()){
            sum += nums[r];
            r++;
            while(sum >= s){
                res = min(r-l, res);
                sum -= nums[l];
                l++;
            }
        }
        if(res==INT_MAX)
            return 0;
        return res;
    }
};

// nlogn
// 这个思路就是暴力搜索法用binary优化的算法。但自己仍然写不出这个关键的search算法
// 就是给一个target，找到一组数组中第一个大于他的数字
// 自己真的太撒比了
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), sums[len + 1] = {0}, res = len + 1;
        for (int i = 1; i < len + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < len + 1; ++i) {
            int right = searchRight(i + 1, len, sums[i] + s, sums);
            if (right == len + 1) break;
            if (res > right - i) res = right - i;
        }
        return res == len + 1 ? 0 : res;
    }
    int searchRight(int left, int right, int key, int sums[]) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (sums[mid] >= key) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};