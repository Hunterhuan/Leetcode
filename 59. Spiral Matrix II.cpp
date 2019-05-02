class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int count = 1;
        while (true) {
            for (int j = left; j <= right; ++j) res[up][j] = count++;
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res[i][right] = count++;
            if (--right < left) break;
            for (int j = right; j >= left; --j) res[down][j] = count++;
            if (--down < up) break;
            for (int i = down; i >= up; --i) res[i][left] = count++;
            if (++left > right) break;
        }
        return res;
    }
};
