// 用dfs 看看能不能到达所有的房间就可以了
// 如果要求路径的话，用一个stack 也是可以的
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> DFS;
        DFS.push(0);
        unordered_set<int> visited = {0};
        while(!DFS.empty())
        {
            int i = DFS.top();
            DFS.pop();
            for(auto j : rooms[i])
            {
                if(visited.count(j) == 0)   //没有到过这个房间中
                DFS.push(j);
                visited.insert(j);
                if(visited.size() == rooms.size())  return true;
            }
        }
        return visited.size() == rooms.size();
    }
};