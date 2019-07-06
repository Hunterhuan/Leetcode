class Solution {
public:
    int res(int n)
    {
        int sum=0;
        while(n!=0)
        {
            int tmp=n%10;
            n=n/10;
            sum=sum+tmp*tmp;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        while(1)
        {
            int r=res(n);
            if(r==1)
                return true;
            else
            {
                if(s.find(r)!=s.end())
                    return false;
                n=r;
                s.insert(n);
            }
        }
        
    }
};