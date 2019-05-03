// 普通解法
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int l=nums.size();
        vector<int> a(l,0);
        vector<int> res;
        for(int i=0;i<l;++i)
            a[nums[i]-1]=1;
        for(int i=0;i<l;++i)
        {
            if(a[i]==0)
                res.push_back(i+1);
        }
        return res;
    }
};

// 常数空间的解法
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) continue;
            index = nums[i]-1;
            while(nums[index]){
                int nextNum = nums[index];
                nums[index] = 0;
                index = nextNum - 1;
            }
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=0)
                res.push_back(i+1);
        return res;
    }
};