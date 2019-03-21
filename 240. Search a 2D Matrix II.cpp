// 暴力做题法。很暴力。这是我能想到方法。也算AC了。虽然准确率不是很高
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0)
            return false;
        int n = matrix[0].size();
        if(n==0)
            return false;
        int start_m, start_n;
        int end_m, end_n;
        for(start_m =0;start_m<m;++start_m){
            if(matrix[start_m][n-1] >= target)
                break;
        }
        for(end_m = 0; end_m<m;++end_m){
            if(matrix[end_m][0] > target)
                break;
        }
        for(start_n =0;start_n<n;++start_n){
            if(matrix[m-1][start_n] >= target)
                break;
        }
        for(end_n = 0; end_n<n;++end_n){
            if(matrix[0][end_n] > target)
                break;
        }
        for(int i= start_m; i<end_m;++i){
            int l = start_n, r = end_n;
            while(l<=r){
                int mid = (l+r)/2;
                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] > target)
                    r = mid -1;
                else
                    l = mid +1;
            }
        }
        return false;
    }
};


\\第二种方法。别人的分治法。不断的把矩阵缩小
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size() == 0) return false;

        int i,j,rows = matrix.size(),cols = matrix[0].size();

        i = 0; 
        j = cols-1; 
        while(i < rows && j >= 0)
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;       
    }
};