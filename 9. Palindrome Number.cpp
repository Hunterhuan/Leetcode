// 用vector存下来就可以了。
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        vector<int> a;
        while(x){
            a.push_back(x%10);
            x = x/10;
        }
        int left=0, right=a.size()-1;
        while(left<right){
            if(a[left]!=a[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

// 其他方法类似