// 暴力法，超时了。
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_xor = INT_MIN;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j)
                max_xor = max(max_xor, nums[i]^nums[j]);
        }
        return max_xor;
    }
};

// 自己的想法是对每位来分类。看哪个返回的值最大。
// 第一位是0的分一堆，是1的分一堆。
// 第一位相同的，再根据0 1 分类。
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};


// 自己还是对xor利用不好。
// xor可以用来swap
void swap(int &a,int &b)
{
    a=a^b;
    b=b^a;
    a=a^b;
}

a ^ a= 0
a ^ b = b ^ a
a ^ b ^ c = a ^ (b ^ c)
d = a ^ b ^ c  => a = d ^ b ^ c