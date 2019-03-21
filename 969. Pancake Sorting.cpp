// 选择排序。从后向前，每次选到合适的，然后换到指定位置。
// 但和标准答案不一样。说明思路应该不同。
class Solution {
public:
    void flip(vector<int>& A, int k, vector<int>& res){
        res.push_back(k+1);
        int l = 0, r = k;
        while(l<r){
            int tmp = A[r];
            A[r] = A[l];
            A[l] = tmp;
            l++;
            r--;
        }
        return ;
    }
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for(int i = A.size(); i>0;--i){
            if(A[i-1] == i)
                continue;
            int index;
            for(index = 0;index<i;++index)
                if(A[index]==i)
                    break;
            flip(A, index, res);
            flip(A, i - 1, res);
        }
        return res;
    }
};