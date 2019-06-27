class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) maxHeap.push(num);
        else if(minHeap.empty()){
            if(num > maxHeap.top()){
                int top = maxHeap.top(); maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(top);
            }
            else minHeap.push(num);
        }
        else{
            if((maxHeap.size() + minHeap.size()) % 2 == 1){ // max_size = min_size + 1
                if(num <= maxHeap.top()) minHeap.push(num);
                else{
                    int top = maxHeap.top(); maxHeap.pop();
                    minHeap.push(top);
                    maxHeap.push(num);
                }
            }
            else{
                if(num >= minHeap.top()) maxHeap.push(num);
                else{
                    int top = minHeap.top(); minHeap.pop();
                    minHeap.push(num);
                    maxHeap.push(top);
                }
            }
        }
    }
    
    double findMedian() {
        if((maxHeap.size() + minHeap.size()) % 2 == 1) return (double)maxHeap.top();
        else return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int, vector<int>, less<int>> minHeap;
    
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) maxHeap.push(num);
        else if(minHeap.empty()){
            if(num > maxHeap.top()){
                int top = maxHeap.top(); maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(top);
            }
            else minHeap.push(num);
        }
        else{
            if((maxHeap.size() + minHeap.size()) % 2 == 1){ // max_size = min_size + 1
                if(num <= maxHeap.top()) minHeap.push(num);
                else{
                    int top = maxHeap.top(); maxHeap.pop();
                    minHeap.push(top);
                    maxHeap.push(num);
                }
            }
            else{
                if(num >= minHeap.top()) maxHeap.push(num);
                else{
                    int top = minHeap.top(); minHeap.pop();
                    minHeap.push(num);
                    maxHeap.push(top);
                }
            }
        }
    }
    
    double findMedian() {
        if((maxHeap.size() + minHeap.size()) % 2 == 1) return (double)maxHeap.top();
        else return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int, vector<int>, less<int>> minHeap;
    
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */