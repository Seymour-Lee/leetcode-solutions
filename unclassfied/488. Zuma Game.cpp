class Solution {
public:
    int findMinStep(string board, string hand) {
        int ans = INT_MAX;
        unordered_map<char, int> ch2nums;
        for(auto ch: hand) ch2nums[ch]++;
        dfs(board, ch2nums, ans, 0);
        return ans == INT_MAX? -1: ans;
    }
    
private:
    void dfs(string board, unordered_map<char, int> ch2nums, int &ans, int step){
        if(board.size() == 0){
            ans = min(ans, step);
            return;
        }
        for(auto p: ch2nums){
            if(p.second == 0) continue;
            char ch = p.first;
            for(int pos = 0; board.find(ch, pos) != string::npos; pos++){
                pos = board.find(ch, pos);
                string next = board.substr(0, pos) + string(1, ch) + board.substr(pos);
                // cout<<next<<" ";
                next = remove(next);
                // cout<<next<<endl;
                ch2nums[ch]--;
                dfs(next, ch2nums, ans, step+1);
                ch2nums[ch]++;
            }
        }
    }
    
    int valid(string str){
        for(int i = 0; i+2 < str.size(); i++) if(str[i] == str[i+1] && str[i] == str[i+2]) return i;
        return -1;
    }
    
    string remove(string str){
        int pos = valid(str);
        while(pos != -1 && str.size()){
            int end = pos+2;
            while(end < str.size() && str[pos] == str[end]) end++;
            // cout<<"erase "<<pos<<" "<<end<<" ";
            str.erase(pos, end-pos);
            pos = valid(str);
        }
        return str;
    }
};

//"RRWWRRW"
//"WR"

// "WWGWGW"
// "GWBWR"