class Solution {
public:
    vector<int> pancakeSort(vector<int>& a) {
        vector<int> ans;
        vector<int> s = a;
        sort(s.begin(), s.end());
        for(int i = a.size()-1; s != a && i >= 0; i--){
            int j;
            for(j = 0; a[j] != i+1 && j <= i; j++);
            flip(a, 0, j);
            ans.push_back(j+1);
            flip(a, 0, i);
            ans.push_back(i+1);
        }
        return ans;
    }
    
private:
    void flip(vector<int> &a, int i, int j){
        while(i < j) swap(a[i++], a[j--]);
    }
};