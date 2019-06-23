class Solution {
public:
vector<pair<int,int>> link = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
vector<char> mines = {'B', '1','2','3','4','5','6','7','8'};
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int m = board.size();
    int n = board[0].size();
    if(board[click[0]][click[1]] == 'M') {board[click[0]][click[1]] = 'X'; return board;}
    dfs(board, click[0], click[1], m, n);
    return board;
}

void dfs(vector<vector<char>>& board, int i, int j, int m, int n){
    if(i < 0 || i >= m || j < 0 || j >= n) return;
    if(board[i][j] == 'E'){
        int count = 0;
        for(auto d : link){
            int tmpi = i + d.first;
            int tmpj = j + d.second;
            if(tmpi >= 0 && tmpi < m && tmpj >= 0 && tmpj < n){
                if(board[tmpi][tmpj] == 'M') count++;
            }
        }
        board[i][j] = mines[count];
        if(board[i][j] == 'B'){
            for(auto lk : link){
                dfs(board, i+lk.first, j+lk.second, m, n);
            }
        }
    }
}
};