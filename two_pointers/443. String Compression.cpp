class Solution {
public:
    int compress(vector<char>& chars) {
        int anchor = 0, write = 0;
        for (int read = 0; read < chars.size(); read++) {
            if (read + 1 == chars.size() || chars[read + 1] != chars[read]) {
                chars[write++] = chars[anchor];
                if (read > anchor) {
                    for (auto c: to_string(read - anchor + 1)) {
                        chars[write++] = c;
                    }
                }
                anchor = read + 1;
            }
        }
        return write;
    }
};

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 1) return chars.size();
        int i = 0, j = 0;
        char prev = chars[0];
        int counter = 0;
        while(j < chars.size()){
            if(chars[j] != prev){
                chars[i++] = prev;
                if(counter != 1){
                    string str = to_string(counter);
                    for(auto c: str) chars[i++] = c;
                }
                prev = chars[j++], counter = 1;
            }
            else{
                j++, counter++;
            }
        }
        chars[i++] = prev;
        if(counter != 1){
            string str = to_string(counter);
            for(auto c: str) chars[i++] = c;
        }
        return i;
    }
};