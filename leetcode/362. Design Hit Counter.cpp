class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        hitcounter = 0;
        hitstart = 1.0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hitcounter++;
        times.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if(times.size() == 0){
            hitcounter = 0;
            hitstart = 1.0;
            return hitcounter;
        }
        while((timestamp-times.front())/60.0 >= 5.0){
            if(times.size() >= 1){
                times.pop();
                hitcounter--;
            }
            else{
                hitcounter = 0;
                hitstart = 1.0;
                return hitcounter;
            }
        }
        return hitcounter;
    }
    
private:
    int hitcounter;
    double hitstart;
    queue<int> times;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */