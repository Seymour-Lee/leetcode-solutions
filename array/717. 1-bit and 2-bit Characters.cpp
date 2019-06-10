class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        for(; i < bits.size()-1; i++){
            if(bits[i] == 1) i++;
        }
        return i == bits.size()-1;
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        for(; i < bits.size()-1; i++){
            if(bits[i] == 1) i++;
        }
        return i == bits.size()-1;
    }
};