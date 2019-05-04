class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        int area = 0;
        vector<pair<int,int>> visited;
        //if no element
        if (grid.size() == 0 )
            return 0;
        
        //if only one element
        for (int i = 0 ; i < grid.size(); i++ )
        {
            for (int j = 0; j < grid[0].size(); j++ )
            {   
                area = dfs (grid, i, j, visited);
               // cout << "area " << area;
                maxArea = area > maxArea ? area : maxArea;
            }
        }
        return maxArea;
    }
    
    bool isValidPath(int i, int j, vector<vector<int>>& grid, vector<pair<int,int>>& visited)
    {
        bool isValid = true;
        if ( i < 0 || j < 0 )
            isValid = false;
        
        if ( i >= grid.size() || j >= grid[0].size() )
            isValid = false;
        if ( isValid && find(visited.begin(), visited.end(), make_pair(i,j) ) != visited.end() )
            isValid = false;
        
        if ( isValid && grid[i][j] == 0 )
            isValid = false;
        
        return isValid;
            
    }
    int dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int,int> > &visited)
    {
        visited.push_back({i,j}); 
        int sum = 0;
        //cout << i << " " << j << endl;
        if ( grid[i][j] == 0 )
            return 0;
        sum++ ; //include this i,j element
        int nextX = i+1;
        int nextY = j;
        if ( isValidPath(nextX, nextY, grid, visited) )
        {
            sum += dfs(grid, nextX, nextY, visited);
        }
        nextX = i-1;
        nextY = j;
        if ( isValidPath(nextX, nextY, grid, visited) )
        {
            sum += dfs(grid,nextX, nextY, visited);
        }
        nextX = i;
        nextY = j+1;
        if ( isValidPath(nextX, nextY, grid, visited) )
        {
            sum += dfs(grid,nextX, nextY, visited);
        }
        nextX = i;
        nextY = j-1;
        if ( isValidPath(nextX, nextY, grid, visited) )
        {
           sum += dfs(grid, nextX, nextY, visited);
        }
        
        return sum;
    }

};