// 非常巧妙的题。很厉害。
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = nums[0], curMax = product, curMin = product;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(curMax, curMin);
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);
            product = max(product, curMax);
        }
        return product;
    }
};

/*

要考虑到一种特殊情况，即负数和负数相乘：如果前面得到一个较小的负数，和后面一个较大的负数相乘，得到的反而是一个较大的数，如{2，-3，-7}，所以，我们在处理乘法的时候，除了需要维护一个局部最大值，同时还要维护一个局部最小值，由此，可以写出如下的转移方程式：

max_copy[i] = max_local[i]
max_local[i + 1] = Max(Max(max_local[i] * A[i], A[i]),  min_local * A[i])

min_local[i + 1] = Min(Min(max_copy[i] * A[i], A[i]),  min_local * A[i])
*/