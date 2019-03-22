// 效率100% 不错。
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res;
        int tmp = abs(A-B);
        for(int i=0;i<min(min(A,B),tmp);++i)
            res += (A>B)? "aab":"bba";
        tmp = min(A,B)-tmp;
        if(tmp>=0){
            for(int i=0;i<tmp;++i)
                res += (A>B)? "ab" : "ba";
        }
        else{
            for(int i=0;i<-tmp;++i)
                res += (A>B)? "a" : "b";
        }
        return res;
    }
};

// 可以看看别人的solution
// 这个是通过count 来计算的。不错
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        // just expand some a or b inside of "ababab..."
        int n=min(A,B);
        string s;
        A-=n;
        B-=n;
        for (int i=0;i<n;++i){
            if (A>0){
                s+="aa";
                --A;
            }
            else s+="a";
            if (B>0){
                s+="bb";
                --B;
            }
            else s+="b";
        }
        if (A>2||B>2) throw nullptr;
        if (A==1) s+="a";
        if (A==2) s+="aa";
        if (B==1) s="b"+s;
        if (B==2) s="bb"+s;
        return s;
    }
};