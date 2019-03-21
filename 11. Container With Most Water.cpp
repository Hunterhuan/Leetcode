// 非常经典的一道题。Two pointers 的题。
// 一定要掌握。但不是很理解是根据什么来 --r ++l的。
// 不明白其最优性。

// 找到了Ans
//则之后保留该条垂直线的所有容器，容量都不可能超过该容器，
//因为随着遍历向中间进行，容器的长度在缩小，
//而这样遍历得到的容器的高度不可能超过初始高度，从而体积也更小。
//因此之后的遍历若想得到更大的容器，
//则一定不能保留较短的那条垂直线。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while(l<r){
            res = max(res, min(height[l], height[r])*(r-l));
            height[l]<height[r] ? ++l: -- r;
        }
        return res;
    }
};