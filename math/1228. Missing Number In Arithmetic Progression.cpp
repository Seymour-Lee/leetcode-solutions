class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int dx = (arr.back()-arr[0])/((int)arr.size());
        //cout<<dx<<endl;
        for(int i = 1; i < arr.size(); i++){
            if((arr[i]-arr[i-1]) != dx) return arr[i]-dx;
        }
        return 0;
    }
};