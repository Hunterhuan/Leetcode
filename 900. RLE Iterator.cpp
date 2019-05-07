class RLEIterator {
public:
    RLEIterator(vector<int>& A) : itr(A.begin()), END(A.end()), c(A.empty() ? 0 : A[0])
    {}
    
    int next(int n) {
        int last = -1;
        while(n > 0 && itr != END) {
            if(c > n) { // if the remaning current element count is more than requested
                c -= n; 
                last = *(itr+1);
                break; // no need to advance itr
            }
            n -= c; // n >= c, need to advance itr
            if(n == 0) last = *(itr + 1);
            itr+=2;
            if(itr != END) c = *itr;
        }
        return last;
    }
    
private:
    vector<int>::const_iterator itr; 
    const vector<int>::const_iterator END;
    int c;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */