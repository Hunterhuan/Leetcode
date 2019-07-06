class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // special cases
        if(numerator == 0)
            return "0";
        string ret = "";
        // type conversion in case of INT_MIN
        long long n = numerator;
        long long d = denominator;
        // sign
        int sign = 1;
        bool digit = false;
        if((n<0) ^ (d<0))
            sign = -1;
        n = abs(n);
        d = abs(d);
        unordered_map<long long, int> m;  // numerator --> position
        while(true)
        {
            if(n < d)
            {
                if(digit == false)
                {
                    if(ret == "")
                        ret = "0.";
                    else
                        ret += ".";
                    digit = true;
                }
                n *= 10;
            }
            int r = n - n/d*d;
            if(r == 0)
            {
                ret += to_string(n/d);
                if(sign == -1)
                    ret = "-" + ret;
                return ret;
            }
            else
            {
                if(digit == true)
                {// check recurring
                    if(m.find(n) == m.end())
                    {
                        ret += to_string(n/d);
                        m[n] = ret.size()-1;
                    }
                    else
                    {
                        int pos = m[n];
                        ret = ret.substr(0, pos) + "(" + ret.substr(pos) + ")";
                        if(sign == -1)
                            ret = "-" + ret;
                        return ret;
                    }
                }
                else
                {
                    ret += to_string(n/d);;
                }
                n = r;
            }
        }
    }
};