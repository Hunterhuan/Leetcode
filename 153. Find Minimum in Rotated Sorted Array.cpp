// 这种边界问题总是搞错。
// 一个是while循环中的小于还是小于等于
// 一个是left和right如何变
class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1;
        if(num[left]<=num[right])
            return num[0];
        while(left < right){
            if(left == right - 1)
                return min(num[left], num[right]);
            int mid = (left + right)/2;
            if(num[mid] > num[left])
                left = mid;
            else
                right = mid;
        }
        return 0;
    }
};