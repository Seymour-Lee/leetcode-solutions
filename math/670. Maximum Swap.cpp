class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> last(10, 0);
        for(decltype(str.size()) i = 0; i != str.size(); i++) 
            last[str[i] - '0'] = i;
        for(decltype(str.size()) i = 0; i != str.size(); i++){
            for(int d = 9; d > str[i]-'0'; d--){
                if(last[d] > i){
                    swap(str[i], str[last[d]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};

class Solution {
public:
    int maximumSwap(int a) {
        string num = to_string(a);
        vector<int> pos(10, -1);
        for(int i = 0; i < num.size(); i++) pos[num[i]-'0'] = i;
        for(int i = 0; i < num.size(); i++){
            for(int d = 9; d > num[i]-'0'; d--){
                if(pos[d] > i){
                    swap(num[i], num[pos[d]]);
                    return stoi(num);
                }
            }
        }
        return a;
    }
};

class Solution {
public:
    int maximumSwap(int a) {
        string num = to_string(a);
        vector<int> pos(10, -1);
        for(int i = 0; i < num.size(); i++) pos[num[i]-'0'] = i;
        for(int i = 0; i < num.size(); i++){
            for(int d = 9; d > num[i]-'0'; d--){
                if(pos[d] > i){
                    swap(num[i], num[pos[d]]);
                    return stoi(num);
                }
            }
        }
        return a;
    }
};