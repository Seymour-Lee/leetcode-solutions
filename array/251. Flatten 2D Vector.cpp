class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        this->vec2d = vec2d;
        ritor = this->vec2d.begin();
        while(ritor != this->vec2d.end() && ritor->size() == 0) ritor++;
        if(ritor != this->vec2d.end()) citor = ritor->begin();
    }

    int next() {
        if(hasNext() == false) return -1;
        int ans = *citor;
        if(citor+1 == ritor->end()){
            ritor++;
            while(ritor != this->vec2d.end() && ritor->size() == 0) ritor++;
            if(ritor != this->vec2d.end()) citor = ritor->begin();
        }
        else{
            citor++;
        }
        return ans;
    }

    bool hasNext() {
        if(vec2d.size() == 0) return false;
        return ritor != vec2d.end() && citor != (vec2d.end()-1)->end();
    }
    
private:
    vector<vector<int>> vec2d;
    vector<vector<int>>::iterator ritor;
    vector<int>::iterator citor;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        rb = v.begin(), re = v.end();
        if(rb != re) cb = rb->begin(), ce = rb->end();
        while(rb != re && cb == ce){
            rb++;
            if(rb != re) cb = rb->begin(), ce = rb->end();
        }
    }
    
    int next() {
        int ans = *(cb++);
        while(rb != re && cb == ce){
            rb++;
            if(rb != re) cb = rb->begin(), ce = rb->end();
        }
        return ans;
    }
    
    bool hasNext() {
        return rb != re;
    }
    
private:
    vector<vector<int>>::iterator rb, re;
    vector<int>::iterator cb, ce;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */