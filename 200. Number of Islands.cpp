class Solution {
public:
    vector<int> UN;
    int count=0;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0||grid[0].size()==0)return 0;
        int length = grid.size()*grid[0].size();
        int width = grid[0].size();
        UN = vector<int>(length,0);
        for(int i=0;i<length;i++){
            int x=i/width,y=i%width;
            if(grid[x][y]=='1')count++;
            UN[i]=i;
        }
        cout<<count<<endl;
        for(int j=0;j<length;j++){
            int x=j/width,y=j%width;
            int down=x+1,right=y+1;
            if(down<grid.size()&&grid[x][y]=='1'&&grid[down][y]=='1')
             unionset(j,j+width);
            if(right<grid[0].size()&&grid[x][y]=='1'&&grid[x][right]=='1')
             unionset(j,j+1);
        }
        return count;
    }

    void unionset(int m,int n){
        int rootM=find(m);
        int rootN=find(n);
        if(rootM==rootN)return;
        UN[rootN]=rootM;
        //cout<<rootM<<" "<<rootN<<endl;
        count--;
    }

    int find(int p){
        while(p!=UN[p]){
            UN[p]=UN[UN[p]];
            p=UN[p];
        }
        return p;
    }
};