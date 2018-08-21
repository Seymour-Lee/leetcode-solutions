class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string result = "";
        string word = "";
        istringstream is(sentence);
        vector<string> words;
        while(getline(is, word, ' ')){
            if(word != ""){
                words.push_back(word);
            }
        }
        set<string> st;
        for(auto d: dict) st.insert(d);
        for(auto w: words){
            string prefix = "";
            for(int i = 0; i <= w.size(); i++){
                prefix = w.substr(0, i);
                if(st.find(prefix) != st.end()) break;
            }
            if(result.size() > 0) result += " ";
            result += prefix;
        }
        return result;
    }
};