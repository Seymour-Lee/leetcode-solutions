class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while(mask & num) mask = mask << 1;
        return ~mask & ~num;
    }
};

class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int pos = 0;
        while((num >> pos)) pos++;
        for(int i = 0; i < pos; i++){
            if(((num >> i) & 1) == 0) ans += (1 << i);
        }
        return ans;
    }
};