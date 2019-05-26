class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(log2time.find(message) == log2time.end() || timestamp - log2time[message] >= 10){
            log2time[message] = timestamp;
            return true;
        }
        else{
            return false;
        }
    }
    
private:
    unordered_map<string, int> log2time;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(str2time.find(message) == str2time.end()){
            str2time[message] = timestamp;
            return true;
        }
        int last = str2time[message];
        if(timestamp-last < 10) return false;
        str2time[message] = timestamp;
        return true;
    }
    
private:
    unordered_map<string, int> str2time;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */