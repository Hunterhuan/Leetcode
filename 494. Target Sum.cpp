// 暴力法
class Solution {
public:
    int cnt = 0;
    void count(vector<int>& nums, int i, int sum, int S){
        if(i==nums.size()){
            if(sum==S)
                ++cnt;
        }
        else{
            count(nums, i+1, sum+nums[i], S);
            count(nums, i+1, sum-nums[i], S);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        count(nums, 0,0,S);
        return cnt;
    }
};




// dynamic programming
// 效率高太多了
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
            int total = 0;
            for (auto num : nums) {
                total += num;
            }
            S = abs(S);  // S or -S leads to the same result
            if (S > total) return 0;
            int V = S + total * 2;   // the backpack capacity in the first loop, and decreases in every next loop
            vector<int> this_F(V+1, 0);    
            vector<int> last_F(V+1, 0); 
            last_F[0+total] = 1;
            int curr_sum = 0;
            for (auto num : nums) {
                curr_sum += num;
                for (int v = total-curr_sum+S; v >= curr_sum-total; v --) {
                    this_F[v+total] = last_F[v+num+total]+last_F[v-num+total];
                }
                last_F.swap(this_F); // swap current result and the result produced in the last loop
            } 
            return last_F[S+total];
        }
};