class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size() < 3) return false;
        int sum = 0;
        for(auto a: A) sum += a;
        if(sum % 3 != 0) return false;
        int ans = sum / 3;
        // cout<<ans<<" "<<sum<<endl;
        sum = 0;
        int counter = 0;
        for(auto a: A){
            sum += a;
            if(sum == ans) sum = 0, counter++;
        }
        return counter == 3;
    }
};

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if(sum % 3 != 0) return false;
        int sub = sum / 3;
        int counter = 0;
        int cur = 0;
        for(auto a: A){
            cur += a;
            if(cur == sub) counter++, cur = 0;
        }
        return counter == 3;
    }
};