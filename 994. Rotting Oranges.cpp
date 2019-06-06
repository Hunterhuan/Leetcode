class Solution {
public:
    void PUSH(int i,int j,std::queue<pair<int,int>> & q,vector<vector<int>>& grid,int &fresh)
    {
             if(i>=0 &&i<grid.size()&&j>=0&&j<grid[i].size() &&grid[i][j]==1) 
             {
                 grid[i][j]=2;
                 fresh--;
                 q.push(pair<int,int>(i,j));
             }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int dTime=0;
        int row=0;
        int col=0;
        std::queue<pair<int,int>> adjacent;
        for(vector<vector<int>>::iterator iter=grid.begin();iter!=grid.end();++iter)
        {
            col=0;
            for(vector<int>::iterator ivter=grid[row].begin();ivter!=grid[row].end();++ivter)
            {
                int value=*ivter;
                if(value==2)   adjacent.push(pair<int,int>(row,col));
                else if(value==1)  fresh++;
                col++;
            }
            row++;
        }
          while(fresh!=0)
         {
              if(adjacent.size()==0)        return -1;
                        int size=adjacent.size();
                        for(int i=0;i<size;++i)
                        {
                             pair<int,int> V=adjacent.front();
                             adjacent.pop();
                             PUSH(V.first-1,V.second,adjacent,grid,fresh);
                            PUSH(V.first,V.second+1,adjacent,grid,fresh);
                            PUSH(V.first+1,V.second,adjacent,grid,fresh);
                            PUSH(V.first,V.second-1,adjacent,grid,fresh);
                        }
                        if(adjacent.size()>0)    ++dTime;
                       
                    
        }
               
        
       return dTime; 
    }
};