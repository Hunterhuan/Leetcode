// 读完题就感觉只能brute force 去做。考验基本功吧
class Solution {
public:
    
    bool magic(vector<vector<int>>& g, int x, int y) {
        
        int a = 0, b = 1;
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int c = g[i+x][j+y];
                a += c;
                b *= c;
            }
        }
        
        return 
            a == 45 && b == 362880 &&
            g[x][y] + g[x][y+1] + g[x][y+2] == 15 &&
            g[x+1][y] + g[x+1][y+1] + g[x+1][y+2] == 15 &&
            g[x+2][y] + g[x+2][y+1] + g[x+2][y+2] == 15 &&
            g[x][y] + g[x+1][y] + g[x+2][y] == 15 &&
            g[x][y+1] + g[x+1][y+1] + g[x+2][y+1] == 15 &&
            g[x][y+2] + g[x+1][y+2] + g[x+2][y+2] == 15 &&
            g[x][y] + g[x+1][y+1] + g[x+2][y+2] == 15 &&
            g[x+2][y] + g[x+1][y+1] + g[x][y+2] == 15;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        
        int result = 0;
        
        for(int i = 0; i + 2 < m; i++) {
            for(int j = 0; j + 2 < n; j++) {
                if(magic(grid, i, j)) result++;
            }
        }
        return result;
    }
};