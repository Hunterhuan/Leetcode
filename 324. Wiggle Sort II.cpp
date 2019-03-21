// 只能想到这种方法。
// 先sort，然后从中间断开。将两段combine到一起就可以了。
// O(n) space
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n; 
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }
};


// 但题目要求是O(n) time and/or O(1) space.
// 两个都做不到。太难受了。只能看别人的answer

// 与中位数有关
// 别人的代码，显示找到第n个。但这个是O(n)的time 吗？

//之前我们是独立的插入大于或者小于中位数的数, 现在我们可以同时做, 也就是, 遍历数组的时候如果当前的数大于中位数就将其从左往右放奇数位置, 
// 如果小于中位数就将其从右往左放在偶数位置. 这样还需要解决的一个问题是如何可以互不干扰的放到正确位置. 举个栗子: 1, 1, 2, 2, 2, 3这六个数:

// 我们可以按照这样一个顺序将数组索引拉开成这样: 1, 3, 5, 0, 2, 4, 也就是我们可以按照这样一个顺序来遍历数组, 
//同时维护一个低位指针用来代表奇数位置已经放到哪里, 和一个高位指针来表示偶数位置已经放到哪里, 
//这样在我们遍历数组的每一个元素的时候就可以按照这样的方式将元素分别放高位还是低位. 
//而要将数组按照这样索引的方式遍历我们只需要一个映射即可, 即(2*i+1)%(len|1).

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	// 找到中位数
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        int len=nums.size(), low=0, high=len-1, mid =nums[len/2], i=0;
        auto index = [=](int pos){ return (1+pos*2)%(len|1); };
        while(i <= high)
        {
            if(nums[index(i)] > mid) swap(nums[index(i++)], nums[index(low++)]);
            else if(nums[index(i)]<mid) swap(nums[index(i)],nums[index(high--)]);
            else i++;
        }
    }
};