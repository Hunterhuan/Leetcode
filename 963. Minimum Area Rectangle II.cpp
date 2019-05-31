auto __ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct myHash 
{
    size_t operator()(pair<int, int> __val) const
    {
        return static_cast<size_t>(__val.first * 101 + __val.second);
    }
};
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        //这题的question 是给你一些点,如何找到最小的矩形呢,这个问题,有点难,需要我们花大量的时间去思考问题.
        //如何做到一个技术男是一种学问
        //考虑到一个平行四边形问题,
        //我们有   对于对顶点(p2,p3) and (p1,p4) 我们有 p1+p4 = p2+p3  可以从向量角度来解释 p4 = p2+p3-p1
        // 判断我们的脚是否是直角的操作,也非常的方便我们只需判断,(p2-p1).(p3-p1) = 0 即可
        // 其他的方法是关于iterate centers
        //key1  --->  radicus   key2--->center  val-----> all point satisfied this question
        
        int N = points.size();
        
        unordered_set<pair<int,int>,myHash > sets;
        for(int i = 0;i<N;i++)
        {
            sets.insert(pair<int,int>(points[i][0],points[i][1]));
        }
        double ans = INT_MAX;
        //fix one point the other points is oppsite point
        for(int  i = 0;i<N;i++)
        {
            auto p1 = pair<int,int>(points[i][0],points[i][1]);
            for(int j = 0;j<N;j++)
            {
                if(j==i)
                    continue;
                auto p2 = pair<int,int>(points[j][0],points[j][1]);
                for(int k = j+1;k<N;k++)
                {
                    if(k ==i)
                    {
                        continue;
                    }
                    auto p3 = pair<int,int>(points[k][0],points[k][1]);
                    pair<int,int> p4;
                    p4.first = p2.first+p3.first-p1.first;
                    p4.second = p2.second+p3.second-p1.second;
                    //构成平行四边形
                    if(sets.count(p4))
                    {
                        pair<int,int> l1,l2;
                        l1.first = p1.first-p2.first;
                        l2.first = p1.first-p3.first;
                        l1.second = p1.second-p2.second;
                        l2.second = p1.second-p3.second;
                        int degree = l1.first*l2.first+l1.second*l2.second;
                        if(degree == 0)
                        {
                            double area = longth(l1)*longth(l2);
                            ans = ans>area?area:ans;
                        }
                        
                    }
                    
                }
            }
        }
        return ans == INT_MAX?0:ans;
    }
    double longth(pair<int,int> & x)
    {
        return sqrt(x.first*x.first+x.second*x.second);
    }
        
};