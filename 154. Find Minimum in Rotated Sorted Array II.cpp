//感觉自己像傻逼一样，做了这么多道题还是不知道边界问题的解决方法。
// 这种是遍历搜索。效率也算挺高的。但自己写出来的
class Solution {
public:
    int findMin(vector<int>& num) {
        int left = 0, right = num.size()-1;
        if(num[left] >= num[right]){
            int min_num = num[right];
            for(int i=right; i>=left;--i){
                if(num[i] > min_num)
                    return min_num;
                else
                    min_num = num[i];
            }
            return min_num;
        }
        else{
            return num[0];
        }
        return 0;
    }
};

//影响到了算法的时间复杂度。原来我们是依靠中间和边缘元素的大小关系，来判断哪一半是不受rotate影响，仍然有序的。而现在因为重复的出现，如果我们遇到中间和边缘相等的情况，我们就无法判断哪边有序，因为哪边都有可能有序。假设原数组是{1,2,3,3,3,3,3}，那么旋转之后有可能是{3,3,3,3,3,1,2}，或者{3,1,2,3,3,3,3}，这样的我们判断左边缘和中心的时候都是3，我们并不知道应该截掉哪一半。解决的办法只能是对边缘移动一步，直到边缘和中间不在相等或者相遇，这就导致了会有不能切去一半的可能。所以最坏情况就会出现每次移动一步，总共移动n此，算法的时间复杂度变成O(n)。


class Solution {
public:
    int findMin(vector<int>& num) {
        int l = 0, r = num.size()-1;
        int min_num = num[0];
        while(l<r-1){
            int mid = (l+r)/2;
            if(num[l] < num[mid]){
                min_num = min(num[l], min_num);
                l = mid + 1;
            }
            else if(num[l] > num[mid]){
                min_num = min(num[mid], min_num);
                r = mid - 1;
            }
            else
                ++l;
        }
        min_num = min(num[r], min_num);
        min_num = min(num[l], min_num);
        return min_num;
    }
};