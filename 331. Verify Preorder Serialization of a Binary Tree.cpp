// 没思路。放在stack下面，也没想到用stack怎么做。
// solution 1: 看不懂
// 效率很高。但不懂
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int length = preorder.size();
        int t=1;
        for (int i=0;i<length;i++) {
            if (preorder[i]==',') continue;
            if (i>0 && preorder[i-1]!=',') continue;
            if (--t<0) return false;
            if (preorder[i]!='#') t+=2;
        }
        return t==0;
    }
};

// 1. 数字的个数总是比#号少一个

// 2. 最后一个一定是#号
// 那么我们加入先不考虑最后一个#号，那么此时数字和#号的个数应该相同，如果我们初始化一个为0的计数器，遇到数字，计数器加1，遇到#号，计数器减1，那么到最后计数器应该还是0。

//https://www.cnblogs.com/grandyang/p/5174738.html

// ans: 转载discuss上一个思路，连续遇到两个“#”，说明这是叶子节点，删去他们及他们的根节点，用一个’#‘代替，
// 直到最后剩一个’#‘说明是二叉树。否则，返回false。
// 这个想法能理解