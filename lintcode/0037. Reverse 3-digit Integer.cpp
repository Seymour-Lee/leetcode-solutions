class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        // write your code here
        string str = to_string(number);
        reverse(str.begin(), str.end());
        return stoi(str);
    }
};