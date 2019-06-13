class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char, int> ch2times;
        for(auto c: licensePlate){
            if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')){
                if('A' <= c && c <= 'Z') ch2times['a' - 'A' + c]++;
                else ch2times[c]++;
            }
        }
        string result = string(16, 'a');
        for(auto word: words){
            if(isValid(ch2times, word)){
                result = word.size() < result.size()? word: result;
            }
        }
        return result;
    }
    
private:
    bool isValid(map<char, int> ch2times, string str){
        for(auto c: str) ch2times[c]--;
        for(auto item: ch2times) if(item.second > 0) return false;
        return true;
    }
};