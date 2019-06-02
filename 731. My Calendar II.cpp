class MyCalendarTwo {
public:
    map<int, int> m;
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        m[start] ++;
        m[end] --;
        int s = 0;
        for (auto it : m) {
            s += it.second;
            if (s >= 3) {
                m[end] ++;
                m[start] --;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */