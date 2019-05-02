class Solution {
public:
void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();
        if(col == 0) return;
        
        bool* record = new bool[row+col];
        memset(record,false,row+col);
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == 0) {
                    record[i] = 1;
                    record[row+j] = 1;
                }
            }
            
        for(int i = 0; i < row; ++i)
            if(record[i]){
                for(int j = 0; j < col; ++j)
                    matrix[i][j] = 0;
            }
        for(int j = row; j < row+col; ++j)
            if(record[j]){
                for(int i = 0; i < row; ++i)
                    matrix[i][j-row] = 0;
            }
    }
};