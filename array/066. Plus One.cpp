class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int sum = digits[digits.size()-1] + 1;
        carry = sum / 10;
        digits[digits.size()-1] = sum % 10;
        for(int i = digits.size()-2; i >= 0; i--){
            sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
            if(carry == 0) break;
        }
        
        if(carry) digits.insert(digits.begin(), carry);
        
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = (digits.back()+1) / 10;
        digits.back() = (digits.back()+1)%10;
        for(int i = digits.size()-2; i >= 0; i--){
            int cur = (digits[i]+c)%10;
            c = (digits[i]+c)/10;
            digits[i] = cur;
        }
        if(c) digits.insert(digits.begin(), c);
        return digits;
    }
};