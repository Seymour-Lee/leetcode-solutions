class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> idx2num;
        int n = sentence.size();
        int num = 0;
        for(int i = 0; i < rows; i++){
            int start = num % n;
            if(idx2num.find(start) == idx2num.end()){
                int cnt = 0;
                for(int i = start, len = 0; len < cols; i = (i+1)%n, cnt++){
                    if(sentence[i].size() + len > cols) break;
                    len += sentence[i].size() + 1;
                }
                idx2num[start] = cnt;
            }
            num += idx2num[start];
        }
        return num / n;
    }
};