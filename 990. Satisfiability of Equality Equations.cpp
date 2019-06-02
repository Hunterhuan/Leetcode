class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = 26;
        DSU dsu(n);
        for(auto equa:equations){
            if(equa[1]=='!')
                continue;
            int a = equa[0]-'a', b = equa[3]-'a';
            dsu.merge(a,b);
        }
        for(auto equa:equations){
            if(equa[1]=='=')
                continue;
            int a = equa[0]-'a', b = equa[3]-'a';
            if(dsu.find(a)==dsu.find(b))
                return false;
        }
        return true;
    }
private:
  class DSU {
    public:
      DSU(int n): parent_(n) {
        for (int i = 0; i < n; ++i)
          parent_[i] = i;
      }
      
      int find(int x) {
        if (parent_[x] != x) parent_[x] = find(parent_[x]);
        return parent_[x];
      }
      
      void merge(int x, int y) {
        parent_[find(x)] = find(y);
      }
    private:
      vector<int> parent_;
  };
};