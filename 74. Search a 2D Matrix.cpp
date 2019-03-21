class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int left = 0, right = m * n -1;
        while(left <= right){
            int middle = (left + right)/2;
            int value = matrix[middle/n][middle%n];
            if(value == target)
                return true;
            else if(value < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return false;
    }
};