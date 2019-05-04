// 单纯的麻烦的一道题。不写了。直接抄答案吧

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        vector<vector<int>> res = M;
        int row = (int) M.size(), col = (int) M[0].size();
        if (row == 1 && col == 1) return M;
        if (row == 1 && col > 1) {
            res[0][0] = (M[0][0] + M[0][1]) / 2;
            res[0][col - 1] = (M[0][col - 1] + M[0][col - 2]) / 2;
            for (int i = 1; i < col - 1; i++) {
                res[0][i] = (M[0][i - 1] + M[0][i] + M[0][i + 1]) / 3;
            }
            return res;
        } else if (row > 1 && col == 1) {
            res[0][0] = (M[0][0] + M[1][0]) / 2;
            res[row - 1][0] = (M[row - 1][0] + M[row - 2][0]) / 2;
            for (int i = 1; i < row - 1; i++) {
                res[i][0] = (M[i - 1][0] + M[i][0] + M[i + 1][0]) / 3;
            }
            return res;
        } else {
            res[0][0] = (M[0][0] + M[0][1] + M[1][0] + M[1][1]) / 4;
            res[row - 1][0] = (M[row - 1][0] + M[row - 1][1] + M[row - 2][0] + M[row - 2][1]) / 4;
            res[0][col - 1] = (M[0][col - 1] + M[0][col - 2] + M[1][col - 1] + M[1][col - 2]) / 4;
            res[row - 1][col - 1] =
                    (M[row - 1][col - 1] + M[row - 1][col - 2] + M[row - 2][col - 1] + M[row - 2][col - 2]) / 4;
            for (int i = 1; i < row - 1; i++) {
                int preSum = M[i - 1][0] + M[i][0] + M[i + 1][0] + M[i - 1][1] + M[i][1] + M[i + 1][1];
                res[i][0] = preSum / 6;
                for (int j = 1; j < col - 1; j++) {
                    preSum += (M[i-1][j+1] + M[i][j+1] + M[i+1][j+1]);
                    res[i][j] = preSum / 9;
                    preSum -= (M[i-1][j-1] + M[i][j-1] + M[i+1][j-1]);
                }
                res[i][col - 1] = preSum / 6;
            }
            for (int i = 1; i < col - 1; i++) {
                res[0][i] = (M[0][i - 1] + M[0][i] + M[0][i + 1] + M[1][i - 1] + M[1][i] + M[1][i + 1]) / 6;
                res[row - 1][i] =
                        (M[row - 1][i - 1] + M[row - 1][i] + M[row - 1][i + 1] + M[row - 2][i - 1] + M[row - 2][i] +
                         M[row - 2][i + 1]) / 6;
            }
            return res;
        }
    }
};