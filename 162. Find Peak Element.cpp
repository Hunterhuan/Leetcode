// 并不是有序的，所以暂时并没有想到如何用二分查找法去做。所以先采用了遍历法。

// 但学习到了定义 INT_MAX 和 INT_MIN.
int minInt = 0x80000000;
int maxInt = 0x7FFFFFFF;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int last = 0x80000000;
        for(int i=0; i<nums.size()-1;++i){
            if(nums[i]>last && nums[i]>nums[i+1]){
                return i;
            }
            last = nums[i];
        }
        return nums.size()-1;
    }
};

// 别人的二分法。很妙。本来以为无序的根本用不了二分法。结果还是可以的。
// 由于题目中提示了要用对数级的时间复杂度，那么我们就要考虑使用类似于二分查找法来缩短时间，由于只是需要找到任意一个峰值，那么我们在确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，如果大于，则说明峰值在前面，如果小于则在后面。这样就可以找到一个峰值了。
// 这可太强了。启发以后对于二分法的题。想一想ans和mid之间的关系。
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};