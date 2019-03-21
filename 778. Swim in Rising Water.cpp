// 代码挺长的，效率一般，使用的是bfs，优先队列来进行遍历。
// 对优先队列的使用应该要记得吧。不然在考场上连使用都不会就尴尬了。

#include <queue>
class Solution {
public:

    struct cmp
    {
        bool operator()(const pair<int, int> p1, const pair<int,int> p2)
        {
            return p1.first > p2.first; //second的小值优先
        }
    };
    bool islegal(int m, int n, int m_1, int n_1){
        if(m_1 < 0 || m_1 >=m)
            return false;
        if(n_1 <0 || n_1 >=n)
            return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<bool> isvisited(m*n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        q.push(pair<int,int> (grid[0][0], 0));
        int min_t = 0;
        isvisited[0] = true;
        while(!q.empty()){
            pair<int, int> tmp = q.top();
            min_t = max(tmp.first, min_t);
            int index_1 = tmp.second/n;
            int index_2 = tmp.second%n;
            if(index_1 == m-1 && index_2 == n-1)
                return min_t;
            q.pop();
            if(islegal(m,n,index_1-1, index_2) && isvisited[tmp.second-n]==false){
                q.push(pair<int, int> (grid[index_1-1][index_2], tmp.second-n));
                isvisited[tmp.second-n] = true;
            }
            if(islegal(m,n,index_1+1, index_2) && isvisited[tmp.second+n]==false){
                q.push(pair<int, int> (grid[index_1+1][index_2], tmp.second+n));
                isvisited[tmp.second+n] = true;
            }
            if(islegal(m,n,index_1, index_2-1) && isvisited[tmp.second-1]==false){
                q.push(pair<int, int> (grid[index_1][index_2-1], tmp.second-1));
                isvisited[tmp.second-1] = true;
            }
            if(islegal(m,n,index_1, index_2+1) && isvisited[tmp.second+1]==false){
                q.push(pair<int, int> (grid[index_1][index_2+1], tmp.second+1));
                isvisited[tmp.second+1] = true;
            }
        }
        return -1;
    }
};



// 大佬的dfs，很强
class Solution
{
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        const int n = grid.size();
        int lp, rp, mp;
        for (lp = grid[0][0], rp = n * n - 1; lp < rp;) 
        {
            mp = lp + (rp - lp) / 2;
            if (valid(grid, mp))
                rp = mp;
            else
                lp = mp + 1;
        }
        return lp;
    }
    bool valid(vector<vector<int>>& grid, int waterHeight)
    {
        const int n = grid.size();
        vector<int> dir({ -1, 0, 1, 0, -1 });
        vector<vector<bool>> visited(n, vector<bool>(n, 0));        
        return dfs(grid, visited, dir, waterHeight, 0, 0, n);
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<int>& dir, int waterHeight, int row, int col, int n)
    {
        int i, r, c;
        visited[row][col] = true;
        for (i = 0; i < 4; ++i)
        {
            r = row + dir[i], c = col + dir[i + 1];
            if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == false && grid[r][c] <= waterHeight)
            {
                if (r == n - 1 && c == n - 1)
                    return true;
                if (dfs(grid, visited, dir, waterHeight, r, c, n))
                    return true;
            }
        }
        return false;
    }
};