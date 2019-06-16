class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int num = *min_element(A.begin(), A.end());
        string str = to_string(num);
        int sum = 0;
        for(auto c: str) sum += c-'0';
        return sum % 2 == 0;
    }
};