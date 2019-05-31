// dp + dfs
// 对每个位置都进行dfs,中间记录上该点出发最长的长度，是dp的思想


class Solution {
public:
    vector<vector<int>> d;
    int row, column;
    vector<pair<int,int>> increment = {{1,0}, {-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(d[i][j] != 0) return d[i][j];
        d[i][j] = 1;
        for(auto &it:increment){
            if(valid_coordinate(i + it.first, j + it.second) && 
              matrix[i][j] > matrix[i+it.first][j+it.second]){
                d[i][j] = max(d[i][j], dfs(matrix, i + it.first, j+it.second) + 1);
            }
        }
        return d[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        row = matrix.size();
        column = matrix.front().size();
        int res = 0;
        for(int i = 0; i != matrix.size(); i++){
            vector<int> tmp(matrix[i].size(), 0);
            d.push_back(tmp);
        }
        for(int i = 0; i != matrix.size(); i++){
            for(int j = 0; j != matrix[i].size(); j++){
                res = max(res, dfs(matrix, i,j));
            }
        }
        return res;
    }
    
    bool valid_coordinate(int i, int j){
        return i >= 0 && j >= 0 && i < row && j < column;
    }
};
