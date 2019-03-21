// 辣鸡玩意儿
class RecentCounter {
public:
    queue<int>_queue;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while (!_queue.empty() && t-_queue.front()>3000)
            _queue.pop();
        _queue.push(t);
        return _queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */