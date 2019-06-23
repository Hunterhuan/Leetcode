class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> res(image);
        helper(res, sr, sc, newColor);
        return res;
    }
    void helper(vector<vector<int>>& res, int sr, int sc, int newColor) {
        int oriColor = res[sr][sc];
        res[sr][sc] = newColor;
        int nrow = res.size();
        if (nrow < 1) return;
        int ncol = res[0].size();
        if (sr - 1 >= 0 && res[sr - 1][sc] == oriColor && res[sr - 1][sc] != newColor) {
            helper(res, sr - 1, sc, newColor);
        }
        if (sr + 1 < nrow && res[sr + 1][sc] == oriColor && res[sr + 1][sc] != newColor) {
            helper(res, sr + 1, sc, newColor);
        }
        if (sc - 1 >= 0 && res[sr][sc - 1] == oriColor && res[sr][sc - 1] != newColor) {
            helper(res, sr, sc - 1, newColor);
        }
        if (sc + 1 < ncol && res[sr][sc + 1] == oriColor && res[sr][sc + 1] != newColor) {
            helper(res, sr, sc + 1, newColor);
        }
        return;
    }
};