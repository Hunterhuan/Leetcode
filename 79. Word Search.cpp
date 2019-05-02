class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        //从不同的位置开始出发，然后通过深搜寻找结果
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited) {
        //终止条件
        if (index == word.size()) {
            return true;
        }
        //越界
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
            return false;
        }
        //已经访问
        if (visited[x][y]) {
            return false;
        }
        //不相等
        if (board[x][y] != word[index]) {
            return false;
        }
        visited[x][y] = true;
        bool result = dfs(board, word, index + 1, x - 1, y, visited) || dfs(board, word, index + 1, x + 1, y, visited) || dfs(board, word, index + 1, x, y - 1, visited) || dfs(board, word, index + 1, x, y + 1, visited);//分别为上下左右地搜索.
        visited[x][y] = false; //准备回溯,设置回未访问状态.
        return result;
    }
};