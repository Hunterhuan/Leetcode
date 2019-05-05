class MyCalendar {
    vector<pair<int, int>> booking;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(booking.empty()){
            booking.push_back(make_pair(start, end));
            return true;
        }
        else{
            // insert in front
            if(end <= booking[0].first)     {
                booking.insert(booking.begin(), make_pair(start, end));
                return true;
            }
            
            // insert to back
            else if(start >= booking[booking.size() - 1].second){
                booking.push_back(make_pair(start, end));
                return true;
            }
            
            //insert in the middle
            for(int i = 1; i < booking.size(); i++){
                if(start >= booking[i - 1].second && end <= booking[i].first){
                    booking.insert(booking.begin() + i, make_pair(start, end));
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */