class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        map<char, pair<int, int>> table;
        for(int i = 0; i < S.size(); i++){
            if(table.find(S[i]) == table.end()){
                table[S[i]] = pair<int, int>(i, i);
            }
            else{
                table[S[i]].second = i;
            }
        }
        int start = 0, end = table[S[0]].second;
        for(int i = 0; i < S.size(); i++){
            if(i == end){
                result.push_back(end - start + 1);
                start = i + 1;
                if(start < S.size()) end = table[S[start]].second;
            }
            else if(table[S[i]].second > end){
                end = table[S[i]].second;
            }
        }
        return result;
    }
};