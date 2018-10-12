class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "$";
        for(auto str: strs){
            ans += "^";
            for(auto ch: str){
                if(ch == '^') ans += "^^";
                else if(ch == '$') ans += "$$";
                else ans += ch;
            } 
            ans += "$";
        }  
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        bool token = false;
        string str = "";
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '^'){
                if(i < s.size()-1 && s[i+1] == '^') str += c, i++;
                else str = "";
            }
            else if(c == '$'){
                if(i < s.size()-1 && s[i+1] == '$') str += c, i++;
                else{
                    if(token) ans.push_back(str);
                    token = true, str = "", i++;
                }
            }
            else{
                str += c;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));