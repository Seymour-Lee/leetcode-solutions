class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> result;
        sort(A.begin(), A.end());
        vector<bool> used(A.size(), false);
        for(auto b: B){
            int i = 0;
            while(i < A.size() && (A[i] <= b || used[i] == true)) i++;
            if(i == A.size()){
                i = 0;
                while(i < A.size() && used[i] == true) i++;
            }
            used[i] = true;
            result.push_back(A[i]);
        }
        return result;
    }
};