class Solution {
private: 
unordered_map<char,vector<char>> role ={
        {'a',{'e'}},
        {'e',{'a','i'}},
        {'i',{'a','e','o','u'}},
        {'o',{'i','u'}},
        {'u',{'a'}}
    };
unordered_map<char,int> v={{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
int MOD = 1e9+7;
public:
    int countVowelPermutation(int n) {
        int res = 0;
        vector<vector<int>>mem(n,vector<int>(5,-1));
        for(auto it =role.begin();it!=role.end();it++ ){
            mem[n-1][v[it->first]]=dc(n-1,it->first,mem);
            res= res%MOD+mem[n-1][v[it->first]]%MOD;
        }return res%MOD;
    }
    int dc(int n, char c,vector<vector<int>>&mem){
        if (n==0) return 1;
        int sum = 0;
        for(int i = 0; i<role[c].size();i++){
            if(mem[n-1][v[role[c][i]]]==-1)
                mem[n-1][v[role[c][i]]]=dc(n-1,role[c][i],mem);
            sum=sum%MOD+mem[n-1][v[role[c][i]]]%MOD;
        }
        return sum%MOD;
    }
};