class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        queue = vector<int>(k, 0);
        count = 0;
        this->k = k;
        front = k-1;
        rear = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(count == k) return false;
        queue[front] = value;
        front = (front - 1 + k) % k;
        count++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(count == k) return false;
        queue[rear] = value;
        rear = (rear + 1) % k;
        count++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(count == 0) return false;
        front = (front + 1) % k;
        count--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(count == 0) return false;
        rear = (rear -1 + k) % k;
        count--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(count == 0) return -1;
        return queue[(front + 1) % k];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(count == 0) return -1;
        return queue[(rear - 1 + k) % k];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == k;
    }
    
private:
    vector<int> queue;
    int k;
    int count;
    int front;
    int rear;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        q = vector<int>(k, 0);
        size = 0;
        head = 0;
        tail = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        head = (head-1+q.size()) % q.size();
        q[head] = value;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        q[tail] = value;
        tail = (tail+1) % q.size();
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        head = (head+1) % q.size();
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        tail = (tail-1+q.size()) % q.size();
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty()? -1: q[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty()? -1: q[(tail-1+q.size()) % q.size()];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return 0 == size && head == tail;
    }
    
    /** Checks whether the circular deque is full or not. */
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */