// 二维的表示法，挺简单的。

class NumArray {
public:
    NumArray(vector<int> nums) {
        arr = new int[nums.size()+1];
        arr[0] = 0;
        for(int i=1;i<=nums.size();++i){
            arr[i] = arr[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return arr[j+1] - arr[i];
    }
private:
    int* arr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */