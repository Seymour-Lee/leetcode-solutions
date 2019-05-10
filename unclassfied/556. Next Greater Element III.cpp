class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        return next_permutation(num.begin(), num.end())? stoll(num) > INT_MAX? -1: stoi(num): -1;
    }
};