class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        head = 0;
        rear = 0;
        n = k;
        q = vector<int>(k);
        empty = true;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        empty = false;
        q[rear] = value;
        rear = (rear + 1) % n;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head + 1) % n;
        if(head == rear) empty = true;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return q[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return q[(rear-1+n) % n];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return empty;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return empty? false: head == rear;
    }
    
private:
    vector<int> q;
    int head;
    int rear;
    int n;
    bool empty;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q = vector<int>(k, 0);
        size = 0;
        head = 0, tail = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        q[tail] = value;
        tail = (tail+1) % q.size();
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head+1) % q.size();
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty()? -1: q[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty()? -1: q[(tail-1+q.size())%q.size()];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return 0 == size && head == tail;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return q.size() == size && head == tail;
    }
    
private:
    vector<int> q;
    int size;
    int head;
    int tail;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */