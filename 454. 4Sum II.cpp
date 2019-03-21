//我们如果把A和B的两两之和都求出来，在哈希表中建立两数之和跟其出现次数之间的映射，那么我们再遍历C和D中任意两个数之和，

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                ++m[A[i] + B[j]];
            }
        }
        for (int i = 0; i < C.size(); ++i) {
            for (int j = 0; j < D.size(); ++j) {
                int target = -1 * (C[i] + D[j]);
                res += m[target];
            }
        }
        return res;
    }
};

//这种方法用了两个哈希表分别记录AB和CB的两两之和出现次数，然后遍历其中一个哈希表，并在另一个哈希表中找和的相反数出现的次数
// 这种方法比之前的慢
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0, n = A.size();
        unordered_map<int, int> m1, m2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++m1[A[i] + B[j]];
                ++m2[C[i] + D[j]];
            }
        }
        for (auto a : m1) res += a.second * m2[-a.first];
        return res;
    }