// 最简单的思路就是遍历，竟然只有8ms，厉害。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();++i){
            if(nums[i] == target)
                return i;
        }
        return -1;
    }
};

// 更新版。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        if(target >= nums[0]){
            for(int i=0;i<nums.size();++i){
                if(nums[i] == target)
                    return i;
            }
        }
        else{
            for(int i=nums.size()-1;i>=0;--i){
                if(nums[i] == target)
                    return i;
            }
        }
        return -1;
    }
};

// 二分搜索法版本, 别人写的
// 自己理解了一下代码，就是用基本的二分搜索。只是这个二分搜索要根据mid的大小来判断mid属于正序还是逆序。然后判断最后的结果在前边还是后边部分。
// 不断递归就可以了。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
        	return -1;
        int begin = 0, end = nums.size()-1;
        while (begin<=end){
            int mid = (begin+end)/2;
            if (nums[mid] == target)
            	return mid;
            if (nums[mid]<nums[nums.size()-1]){
                if (target > nums[mid] && target <=nums[nums.size()-1]){
                    begin = mid+1;
                }
                else end = mid-1;
            }
            else {
                if (target >= nums[0] &&target < nums[mid]){
                    end = mid-1;
                }
                else begin = mid+1;
            }
        }
        return -1;
    }
};