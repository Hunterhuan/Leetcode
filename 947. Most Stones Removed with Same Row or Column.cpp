// 没想到要用并查集去做。
// 要去计算并查集的个数。这样才能做到最多的结果。



class Solution {
    
public:
    int findx(int current, vector<int>& parents) {
        if(parents[current] != current) {
            parents[current] = findx(parents[current], parents);
        }
        return parents[current];
    }
    
    void unionx(int a, int b, vector<int>& parents) {
        int p1 = findx(a, parents);
        int p2 = findx(b, parents);
        if(p1 != p2){
            while(parents[b] != p2) {
                int tmp = b;
                b = parents[b];
                parents[tmp] = p1;
            }
            parents[p2] = p1;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        // Union-find
        // Second Time!
        // Not excited anymore...
        
        // The root parent will be -1.
        // Which will not be counted when counting the result.
        // Since we cannot remove the last stone of the union.
        // The parent of x is parent[x].
        vector<int> parents;
        for(int i = 0; i < stones.size(); i++)
            parents.push_back(i);
        int result = 0;
        
        // Try union all the pairs.
        for(int i = 0; i < stones.size() - 1; i++) {
            for(int j = i + 1; j < stones.size(); j++) {

                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    unionx(i, j, parents);
            }
        }
        
        for(int i = 0; i < parents.size(); i++) {
            if(parents[i] != i)
                result++;
        }

        return result;
    }
};