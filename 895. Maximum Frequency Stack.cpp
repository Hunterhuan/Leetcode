class FreqStack {
public:
    priority_queue<tuple<int,int,int>> s;
    map<int,int> mp;
    int ts;
    
    
    FreqStack() {
        ts = 0;
    }
    
    void push(int x) {
        mp[x]++;
        s.push({mp[x], ts++, x});
    }
    
    int pop() {
        int val = get<2>(s.top());
        s.pop();
        mp[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */