// sort 之后再遍历。也很厉害。
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1])
                return nums[i];
        }
    }
};

// 自己用字典也实现了一次。单效率不是很高。


// 快慢指针。这个也太厉害了吧。根本想不到的。
//其核心思想快慢指针在之前的题目Linked List Cycle II中就有应用，这里应用的更加巧妙一些，
// 由于题目限定了区间[1,n]，所以可以巧妙的利用坐标和数值之间相互转换，
// 由于重复数字的存在，那么一定会形成环，我们用快慢指针可以找到环并确定环的起始位置，
// 确实是太巧妙了！

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};


