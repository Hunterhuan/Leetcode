// 并查集可以用一个数组来表示


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> union_m(M.size(),-1);
        int cnt = 0;
        for(int i = 0 ; i < M.size() ; i++){
            for( int j = i ; j < M.size() ; j++){
                if(M[j][i]){
                    if(union_m[j] == -1 && i == j) // new finding
                        union_m[j] = ++cnt;
                    else if(union_m[j] == -1) // i and j are friend, but j is not included in any group yet
                        union_m[j] = union_m[i];
                    else{  //i and j are friend, but j is already belonged to a group 
                        if(union_m[i] != union_m[j]){
                            int temp = union_m[i];
                            for(int& I : union_m) //make i's group aligned to j's group
                                if(I == temp)
                                    I = union_m[j];
                        }
                    }
                }
            }
        }
        set<int> res; // use STL:set to know how many group we have 
        for(int j  = 0; j < union_m.size() ; j++)
            res.insert(union_m[j]); 
        return res.size();
    }
};