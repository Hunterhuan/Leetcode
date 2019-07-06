class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k == 0) return;
        
        int start = 0;
        int r0 = nums[start];
        int j = k;
		
        for(int i = 0; i < nums.size(); i++) {
            int r1 = nums[j];
            nums[j] = r0;
            r0 = r1;
            
            j += k;
            if(j >= nums.size()) j -= nums.size();
            
            if(j == start){
                nums[j] = r0;
                start++;
                r0 = nums[start];
                j = start + k;
                i++;
            }
        }
    }
};