// 主要就是Binary Indexed Tree的数据结构的练习
// https://blog.csdn.net/Yaokai_AssultMaster/article/details/79492190
// 这篇文章讲得很细致
class NumArray {
private:
    vector<int> BITree;
    vector<int> _nums;
    
    void updateBIT(int index, int val) {
        index++;
        while (index < BITree.size()) {
            BITree[index] += val;
            index += (index & (-index));
        }
    }
    
    int getSum(int index) {
        int sum = 0;
        index++;
        while (index > 0) {
            sum += BITree[index];
            index -= (index & (-index));
        }
        return sum;
    }

public:
    NumArray(vector<int> nums) : _nums(nums) {
        if (nums.empty()) return;
        int n = nums.size();
        BITree.resize(n+1);
        for (int i=0; i<n; i++) {
            updateBIT(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        if (_nums.empty() || i < 0 || i >= _nums.size()) return;
        if (_nums[i] != val) {
            updateBIT(i, val - _nums[i]);
            _nums[i] = val;
        }
    }
    
    int sumRange(int i, int j) {
        if (_nums.empty() || i < 0 || i >= _nums.size() || j < 0 || j >= _nums.size()) return 0;
        return getSum(j) - getSum(i-1);
    }
};