class Solution {
public:
    map<int, vector<int>>tip;
    int ifbound = 0, row, col;
    int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(int i, int j, vector<vector<int>>& A) {
        int a, b, c, ans;

        tip[i][j] = 1;
        if(i == 0 || j == 0 || i == row - 1 || j == col - 1 )
            ifbound = 1;
        ans = 1;
        for(a=0; a<4; ++a) {
            b = direction[a][0] + i;
            c = direction[a][1] + j;
            if(b >=0 && b < row && c >= 0 && c < col && A[b][c] == 1 && tip[b][c] == 0) {
                ans += dfs(b, c, A);
            }
        }
        return ans;
    }


    int numEnclaves(vector<vector<int>>& A) {
        int i, j, k, res;

        row = A.size();
        col = A[0].size();

        tip.clear();
        vector<int>temp(col);
        for(i=0; i<row; ++i)
            tip[i] = temp;

        res = 0;
        for(i=0; i<row; ++i) {
            for(j=0; j<col; ++j) {
                if(A[i][j] && tip[i][j] == 0) {
                    ifbound = 0;
                    k = dfs(i, j, A);
                    if(ifbound == 0) {
                        res = res + k;
                        
                    }
                }
            }
        }
        return res;


    }
};