// 贪心的规律
// 当序列有一段 连续递增或连续递减的时候，只保留最后一个。
// 因为这样给后面的更大的选择空间


// solution1 : dp dynamic program
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return n;
        vector<int> up(n,0);
        // up[i] 表示以i为顶，最长是多长
        // down[i] 表示以i为底，最长是多长
        vector<int> down(n,0);
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i] > nums[j])
                    up[i] = max(up[i], down[j]+1);
                else if(nums[i]<nums[j])
                    down[i] = max(down[i], up[j]+1);
            }
        }
        return max(down[n-1], up[n-1]);
    }
};


//solution2: linear dynamic programming
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return n;
        // up和down表示和上面solution一样。
        vector<int> up(n,0);
        vector<int> down(n,0);
        up[0] = down[0] = 1;
        for(int i=1;i<n;++i){
            if(nums[i]>nums[i-1]){
                up[i] = down[i-1]+1;
                down[i] = down[i-1];
            }else if(nums[i]<nums[i-1]){
                down[i] = up[i-1]+1;
                up[i] = up[i-1];
            }else{
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(down[n-1], up[n-1]);
    }
};

// solution3: linear dynamic programming 优化了空间
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return n;
        int down = 1, up = 1;
        for(int i=1;i<n;++i){
            if(nums[i]>nums[i-1])
                up = down + 1;
            else if(nums[i]<nums[i-1])
                down = up + 1;
        }
        return max(down, up);
    }
};


// solution4 : greedy
// 这个思路是找到每个峰值，不管是高峰还是低峰。count起来就是最后的结果
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return n;
        int prevdiff = nums[1] - nums[0];
        int count = prevdiff !=0 ? 2 : 1;
        for(int i=2; i<n;++i){
            int diff = nums[i]-nums[i-1];
            if((diff>0 && prevdiff <=0) || (diff<0 && prevdiff >=0)){
                count++;
                prevdiff = diff;
            }
        }
        return count;
    }
};