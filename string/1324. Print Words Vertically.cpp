class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> strs;
        istringstream is(s);
        string str;
        while(getline(is, str, ' ')){
            strs.push_back(string(str.rbegin(), str.rend()));
        }
        vector<string> ans;
        int count = strs.size(); // # of not empty
        while(count != 0){
            count = 0;
            string cur = "";
            for(int i = 0; i < strs.size(); i++){
                // cout<<strs[i]<<endl;
                if(strs[i].size()){
                    cur.push_back(strs[i].back());
                    strs[i].pop_back();
                }
                else cur.push_back(' ');
                if(strs[i].empty() == false) count++;
            }
            ans.push_back(cur);
            // cout<<count<<endl;
        }
        for(auto &str: ans){
            // cout<<str<<endl;
            while(str.back() == ' ') str.pop_back();
        }
        return ans;
    }
};

// "HOW ARE YOU"
// "TO BE OR NOT TO BE"
// "CONTEST IS COMING"