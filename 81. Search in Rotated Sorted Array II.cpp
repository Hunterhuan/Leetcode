// 先写了一个遍历的，结果超过了100%，真好玩
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();++i){
            if(nums[i] == target)
                return true;
        }
        return false;
    }
};

// 再写一个二分法的
// 因为有重复的数字，所以边界问题特别恶心，找了一下别人用二分法写的代码。
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //扫描一遍肯定可以，那么放在这里不是这么简单的,是希望我们用log级别的
        //方法一我们先用师兄的做法，先二分找到那个边界，然后分开进行二分查找即可~
        //方法二用下面这种方法
        
        int len = nums.size();
        int left = 0,right = len-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
            {
                return true;
            }
            if(nums[mid]==nums[left])
                left++;
            else if(nums[mid]>=nums[left])        //砍掉的一半一定要是可以砍掉的
                {
                    if(target<=nums[mid]&&target>=nums[left])
                        right = mid-1;
                    else
                        left = mid+1;
                    
                }
            else
            {
                if(nums[mid]< target&&target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return false;
    }
};

// 这个方法更清真
// 现在数组中允许出现重复数字，这个也会影响我们选择哪半边继续搜索，由于之前那道题不存在相同值，我们在比较中间值和最右值时就完全符合之前所说的规律：如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的。而如果可以有重复值，就会出现来面两种情况，[3 1 1] 和 [1 1 3 1]，对于这两种情况中间值等于最右值时，目标值3既可以在左边又可以在右边，那怎么办么，对于这种情况其实处理非常简单，只要把最右值向左一位即可继续循环，如果还相同则继续移，直到移到不同值为止，然后其他部分还采用 Search in Rotated Sorted Array 在旋转有序数组中搜索 中的方法。
// 这个方法还是很妙的
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return false;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (right + left)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < nums[right]){
                if(nums[mid] < target && nums[right]>=target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if(nums[mid] > nums[right]){
                if(nums[left] <= target && nums[mid] > target)
                    right = mid -1;
                else
                    left = mid + 1;
            }
            else
                --right;
        }
        return false;
    }
};