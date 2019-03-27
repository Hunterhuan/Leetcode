// 最简单的思路，就是不断的rand，直到出现合适的结果
class Solution {
public:
    int m,n;
    unordered_set<int> flag;
    Solution(int n_rows, int n_cols):m(n_rows),n(n_cols),flag() {       
    }
    
    vector<int> flip() {
        int index = rand()%(m*n);
        while (flag.find(index) !=  flag.end())
            index = rand()%(m*n);
        flag.insert(index);
        return vector<int>{index/n,index%n};
    }
    
    void reset() {
        flag.clear();
    }
};

