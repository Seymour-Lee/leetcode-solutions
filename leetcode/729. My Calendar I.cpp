class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto e: calendar){
            if(e.first < end && e.second > start) return false;
        }
        calendar.push_back(pair<int, int>{start, end});
        return true;
    }
    
private:
    vector<pair<int,int>> calendar;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */