// 很巧妙。把一个块分为4小块，然后进行Union Find.
// 先Union 块内的，在分别Union 块与块之间。

// 别人实现的Union Find 很棒很简洁。
class Solution {  
public:
  int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();    
    DSU dsu(4 * n * n);
    for (int r = 0; r < n; ++r)
      for (int c = 0; c < n; ++c) {
        int index = 4 * (r * n + c);
        switch (grid[r][c]) {
          case '/':
            dsu.merge(index + 0, index + 3);
            dsu.merge(index + 1, index + 2);
            break;
          case '\\':
            dsu.merge(index + 0, index + 1);
            dsu.merge(index + 2, index + 3);
            break;
          case ' ':
            dsu.merge(index + 0, index + 1);
            dsu.merge(index + 1, index + 2);
            dsu.merge(index + 2, index + 3);
            break;
          default: break;
        }
        if (r + 1 < n)
          dsu.merge(index + 2, index + 4 * n + 0);
        if (c + 1 < n)
          dsu.merge(index + 1, index + 4 + 3);
      }
    int ans = 0;
    for (int i = 0; i < 4 * n * n; ++i)
      if (dsu.find(i) == i) ++ans;
    return ans;
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