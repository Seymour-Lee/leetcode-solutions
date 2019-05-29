class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0.0;
    }
    
    double next(int val) {
        if(size == 0) return 0.0;
        if(window.size() < size){
            window.push(val);
            sum += val;
        }
        else{
            sum = sum - window.front() + val;
            window.pop();
            window.push(val);
        }
        return sum/(double)window.size();
    }
    
private:
    int size;
    queue<int> window;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        cap = size;
        sum = 0.0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if(q.size() > cap){
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
    
private:
    queue<int> q;
    int cap;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */