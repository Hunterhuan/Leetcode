// 我没写，而是直接copy的答案。
// 思路就是调用两次 robber I的函数，一个是不要第一个，一个是不要最后一个。
// max值就是最后的answer

class Solution {
public:
    int rob(vector<int>& nums) {
        int length=nums.size();
        if(length==0)
            return 0;
        if(length==1)
            return nums[0];
            
        return max(robDiv(nums,0,length-2),robDiv(nums,1,length-1));
    }
    
    int robDiv(vector<int> &nums,int first,int last)
    {
        //因为只需要比较第A[i-2]+nums[i]和A[i-1]的大小，所以可以把House Robber I中的数组也省略掉，
        //而只需要两个变量来存储着两个值，这样更能节约空间。
        //这里pLast存储的是House Robber I中A[i-1]的值，
        //ppLast存储的是House Robber I中A[i-2]的值，逻辑和House Robber I是一样的。
        int pLast=0,ppLast=0;
        for(int i=first;i<=last;i++)
        {
            int tmp=pLast;
            pLast=max(ppLast+nums[i],pLast);
            ppLast=tmp;
        }
        return pLast;
    }
};

