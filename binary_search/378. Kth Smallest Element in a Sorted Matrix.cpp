class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         vector<int> heap;
        for(auto row: matrix){
            for(auto e: row){
                heap.push_back(e);
            }
        }
        auto cmp = [](int a, int b){return a > b;};
        make_heap(heap.begin(), heap.end(), cmp);
        while(--k){
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
        } 
        return heap.front();
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int l = m[0][0], r = m.back().back()+1;
        while(l < r){
            int mid = l + (r - l) / 2;
            int counter = 0;
            int j = m[0].size()-1;
            for(auto row: m) {
                while(j >= 0 && mid < row [j]) j--;
                counter += j+1;
            }
            if(counter < k) l = mid+1;
            else r = mid;
        }
        return l;
    }
};