/*有N件物品和一个容量为V的背包。
第i件物品的费用是c[i]，价值是w[i]。
有的物品是1个，有的物品是n个，有的物品是无限个
求解将哪些物品装入背包可使价值总和最大。
*/
/*考虑到01背包和完全背包的混合问题
在之前的代码中也已经知道，只需要改变遍历的顺序就可以了。
if i件物品是01背包，就逆序，else if是完全背包，那么就顺序

再加上多重背包。
可以将这类物品分成二进制，然后变成01背包类型的物品。
最后就按照之前的思路就可以了。
*/

// 可以优化空间
class Solution {
public:
    // n[i] = 1 是01背包
    // n[i] > 1 是多重背包
    // n[i] = 0 是完全背包
    int knackpack(int N,int V,  vector<int>& n, vector<int>& c, vector<int>&w) {
        vector<int> f(V,0);
        vector<int> tmp_c, tmp_w, tmp_n;
        // 完成转化 成01背包和完全背包的混合问题
        for(int i=0;i<N;++i){
            if(n[i]==0){
                tmp_w.push_back(w[i]);
                tmp_c.push_back(c[i]);
                tmp_n.push_back(0);
            }
            int i= 1;
            while(n[i]>=i){
                n[i] -= i;
                tmp_c.push_back(i*c[i]);
                tmp_w.push_back(i*w[i]);
                tmp_n.push_back(1);
                i = i<<1;
            }
            tmp_c.push_back(n[i]*c[i]);
            tmp_w.push_back(n[i]*w[i]);
            tmp_n.push_back(0);
        }

        for(int i=0;i<tmp_c.size();++i){
            if(tmp_n[i]==1)
                for(int v =V-1 ;v>=c[i] ;--v){
                    f[v] = max(f[v], f[v-tmp_c[i]]+tmp_w[i]);
                }
            else
                for(int v =c[i] ;v<V ;++v){
                    f[v] = max(f[v], f[v-tmp_c[i]]+tmp_w[i]);
                }
        }
        return f[V-1];
    }
};

