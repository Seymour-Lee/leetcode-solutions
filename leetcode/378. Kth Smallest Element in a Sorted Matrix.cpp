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