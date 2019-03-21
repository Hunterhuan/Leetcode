//就是一个binary search 而已

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int middle = (left+right)/2;
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] > target)
                right = middle-1;
            else
                left = middle + 1;
        }
        return left;
    }
};