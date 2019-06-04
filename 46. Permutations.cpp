// 开始还在想怎么才能取出来，看别人是用swap，比较好的。但应该会很占内存。因为每个num都是存在内存里面的。
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        Helper(ret, num, 0);
        return ret;
    }
    void Helper(vector<vector<int> >& ret, vector<int> num, int pos)
    {
        if(pos == num.size()-1)
            ret.push_back(num);
        else
        {
            for(int i = pos; i < num.size(); i ++)
            {//swap all the ints to the current position
                swap(num[pos], num[i]);
                Helper(ret, num, pos+1);
                swap(num[pos], num[i]);
            }
        }
    }
};