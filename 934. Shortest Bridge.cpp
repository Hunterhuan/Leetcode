/*思路：先利用dfs找到其中的两块岛屿，将其中的一块所有的陆地标记改为2，
然后将另一块岛屿中的所有陆地添加到一个队列进行bfs，对于队列中的每一个陆地判断四周方向，
若遇到标记为2的陆地则代表相连了，若遇到标记为1的陆地，则继续判断，若遇到标记为0的水，
则将该块标记为1并添加到队列中，代表陆地向该方向搭了一块桥，就这样不断bfs，直到其中
某一块岛屿或者桥四周遇到了标记为2的陆地，即代表两座岛屿连通了，这样我们队列元素
更新了几个周期即代表桥长为几。*/


class Solution {
private:
    int N;
    int color[105][105];
    int dist[105][105];
    int mx[4] = {-1, 1, 0, 0};
    int my[4] = {0, 0, -1, 1};

    void dfs(int curx, int cury, int c, vector<vector<int>>& A) {
        for (int i = 0; i < 4; i++) {
            int x = curx + mx[i];
            int y = cury + my[i];
            if (x < 0 || x >= N || y < 0 || y >= N || A[x][y] != 1 || color[x][y] != -1) continue;
            color[x][y] = c;
            dfs(x, y, c, A);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& A) {
        N = A.size();
        memset(color, -1, sizeof(color));
        int colorCnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (A[i][j] == 1 && color[i][j] == -1) {
                    color[i][j] = colorCnt;
                    dfs(i, j, colorCnt, A);
                    colorCnt++;
                }
            }

        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (color[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push(make_pair(i, j));
                }
                else
                    dist[i][j] = 1e9;
            }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (color[x][y] == 1) return dist[x][y] - 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + mx[i], ny = y + my[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || dist[nx][ny] <= dist[x][y] +1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
        return -1;
    }
};