这种方法首先对原数组取其转置矩阵，然后把每行的数字翻转可得到结果，如下所示(其中蓝色数字表示翻转轴)：

1  2  3　　　 　　 1  4  7　　　　　  7  4  1

4  5  6　　-->　　 2  5  8　　 -->  　  8  5  2　　

7  8  9 　　　 　　3  6  9　　　　      9  6  3

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};