// solution1: 利用stack
//
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) return true;
            while (!st.empty() && nums[i] > st.top()) {
                third = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};



//solution2 : 
class Solution {
public:
    bool find132pattern(vector<int>& nums) {int n = nums.size(), i = 0, j = 0, k = 0;
        while (i < n) {
            while (i < n - 1 && nums[i] >= nums[i + 1]) ++i;
            j = i + 1;
            while (j < n - 1 && nums[j] <= nums[j + 1]) ++j;
            k = j + 1;
            while (k < n) {
                if (nums[k] > nums[i] && nums[k] < nums[j]) return true;
                ++k;
            }
            i = j + 1;
        }
        return false;
    }
};



solution3:
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mn = min(mn, nums[j]);
            if (mn == nums[j]) continue;
            for (int k = n - 1; k > j; --k) {
                if (mn < nums[k] && nums[j] > nums[k]) return true;
            }
        }
        return false;
    }
};


// https://www.cnblogs.com/grandyang/p/6081984.html