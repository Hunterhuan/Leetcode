class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res,v;
        for(int i=1;i<=N;i++)
            v.push_back(i);
        helper(res,v);
        return res;   
    }
    void helper(vector<int>&res,vector<int> v)
    {
        int size=v.size();
        if(size==1)
            res.push_back(v[0]);
        else
        {
            vector<int> odd,even;
            for(int i=0;i<size;i++)
                i%2?odd.push_back(v[i]):even.push_back(v[i]);
            helper(res,even);
            helper(res,odd);
        }
    }
};