class MyCalendar {
public:
set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=st.lower_bound({start,end});
        if(it!=st.end() && it->first<end){
            return 0;
        }
        if(it!=st.begin()){
        auto previt=prev(it);
        if(start<previt->second){
            return 0;
        }
        }
        st.insert({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */