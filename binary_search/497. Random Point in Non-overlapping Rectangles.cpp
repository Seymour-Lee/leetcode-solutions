class Solution {
public:
    Solution(vector<vector<int>> rects) {
        this->rects = rects;
        for(auto r: this->rects){
            v.push_back(area(r) + (v.empty()? 0: v.back()));
        }
        srand(time(0));
    }
    
    vector<int> pick() {
        int r = rand() % v.back();
        auto itor = upper_bound(v.begin(), v.end(), r);
        int idx = itor - v.begin();
        auto rec = rects[idx];
        return vector<int>{
            rand() % (rec[2] - rec[0] + 1) + rec[0],
            rand() % (rec[3] - rec[1] + 1) + rec[1]
        };
    }
    
private:
    vector<int> v;
    vector<vector<int>> rects;
    
    int area(vector<int> r){
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        int sum = 0;
        for(auto r: rects){
            sum += area(r);
            sums.push_back(sum);
        }
        this->rects = rects;
        srand(time(0));
    }
    
    vector<int> pick() {
        int i = binary(rand()%sums.back());
        auto rec = rects[i];
        return vector<int>{
            rand() % (rec[2] - rec[0] + 1) + rec[0],
            rand() % (rec[3] - rec[1] + 1) + rec[1]
        };
    }
    
private:
    vector<int> sums;
    vector<vector<int>> rects;
    
    int binary(int target){
        int l = 0, r = sums.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(sums[m] < target) l = m+1;
            else r = m;
        }
        return l;
    }
    
    int area(vector<int> r){
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */