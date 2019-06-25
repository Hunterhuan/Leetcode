// 我表示我不会这道题
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int maxval = *max_element(A.begin(), A.end());
        int mask = 1;
        while (maxval >= mask) {
            mask <<= 1;
        }
        mask -= 1;
        unordered_set<int> nums;
        
        for (int i = 0; i < A.size(); ++i) {
            int val =  A[i];
            nums.insert(val);
            for (int j = i - 1; j >= 0 && val != mask; --j) {
                val |= A[j];
                nums.insert(val);
            }
        }
        return nums.size();
    }
};



//如果把mask 的部分删去那么就会超时。mask的意思是指如果继续向前or，结果也不会改变了，因为他已经全是1了。