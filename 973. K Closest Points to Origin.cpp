//对整个sort 一下，但效率有点低。感觉可能是比较的时候每次都计算太慢了。
// 50% 不是很高
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> a;
        for(int i=0;i<points.size();++i)
            a.emplace_back(vector<int>{points[i][0]*points[i][0]+points[i][1]*points[i][1], i});
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        for(int i=0;i<K;++i)
            res.push_back(points[a[i][1]]);
        return res;
    }
};


// 还可以采用快排的时候的方法。
// 对一个benchmark，选出大于它，和小于它的两组。
// 然后再分治
// 效率高


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l=0, r=points.size()-1;
        while(l<=r){
            int par = partition(points,l,r);
            if (par==K-1) break;
            else if (par < K-1) l = par + 1;
            else r = par - 1;
        }
        points.resize(K);
        return points;
    }
    int partition(vector<vector<int>>& points, int l, int r){
        vector<int> pi = points[l];
        while (l<r){
            while (l<r && compare(points[r], pi)>=0) --r;
            points[l] = points[r];
            while (l<r && compare(points[l], pi)<=0) ++l;
            points[r] = points[l];
        }
        points[l] = pi;
        return l;
    }
    int compare(const vector<int>& a, const vector<int>& b){
        return (a[0]*a[0] + a[1]*a[1]) - (b[0]*b[0] + b[1]*b[1]);
    }

};