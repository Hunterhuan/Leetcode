class Solution {
public:
 
    bool notZero(vector<int>& b) {
        for(int i = b.size()-1; i >= 0; i--) {
            if(b[i] > 0) return true;
        }
        
        return false;
    }
    
    void div(vector<int>& b) {
        int tmp = 0;
        for(int i = 0; i < b.size(); i++) {
            b[i] += tmp*10;
            tmp = b[i] % 2;
            b[i] = b[i] / 2;
        }
    }
    
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        
        a = a % 1337;
        
        while(notZero(b)) {
            if(b[b.size()-1] % 2 != 0) ans = (ans * a) % 1337;
            
            div(b);
            
            a = (a * a) % 1337;
        }
        
        return ans;
    }
};




class Solution {
public:
    int superPow(int a, vector<int>& B) {
        int r=1;//result
        const int t = (7-1)*(191-1);//totient of 1337
        int e = 0,d=1;
        //find exponent % totient of 1337
        for(auto ib=rbegin(B);ib!=rend(B);++ib){
            e = (e+d*(*ib))%t;
            d = (d*10)%t;
        }
        //now apply exponent
        a = a%1337;
        while(e){
            if(e&1)r=(r*a)%1337;
            a=(a*a)%1337;
            e=e>>1;
        }
        return r;
    }
};