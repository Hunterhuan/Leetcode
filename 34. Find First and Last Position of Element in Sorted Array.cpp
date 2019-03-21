// 两个代码。都是先binary search， 然后从search到的地方向两个方向search。另外一种。就是直接从两端遍历。貌似也可以

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return vector<int>{-1, -1};
        }
        
        int start = 0;
        int end = nums.size()-1;
        while (start <= end){
            int mid = (start+end)/2;
            if (nums[mid] == target){
                int lower = mid;
                int upper = mid;
                // Getting the start and end position of the replicate
                while (lower-1 >= 0 && nums[lower-1] == nums[lower]) lower--;
                while (upper+1 <= nums.size()-1 && nums[upper+1] == nums[upper]) upper++;
                return vector<int>{lower,upper};
            } else if (nums[mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        
        return vector<int>{-1, -1};
    }
};



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r{size - 1}, mid;
        int index;
        bool found{false};
        
        if(size == 1 && nums[0] == target)
            return {0,0};
        
        // Binary Search
        while(l <= r) {
            mid = (l+r)/2;
            if(nums[mid] > target) {
                r = mid - 1;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                found = true;
                index = mid;
                break;
            }
        }
        
        if(!found)
            return {-1,-1};
        
        // Find Starting Index
        l = index - 1;
        while(l >= 0 && nums[l] == target) {
            --l;
        }
        
        // Find Ending Index
        r = index + 1;
        while(r < size && nums[r] == target) {
            ++r;
        }
        
        return {l + 1, r - 1};
        
    }
};