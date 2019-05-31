class Solution {
public:
    string toGoatLatin(string S) {
        set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string result = "";
        int counter = 1;
        for(int i = 0; i < S.size(); i++){
            int j = i;
            while(S[j] != ' ') j++;
            string str = S.substr(i, j-i) ;
            i = j;
            if(vowel.find(str[0]) == vowel.end() && str.size() > 1){
                str = str.substr(1, str.size()-1) + str[0] + "ma" + string(counter, 'a');
            }
            else{
                str = str + "ma" + string(counter, 'a');
            }
            result +=" " + str;
            counter++;
        }
        return result.substr(1, result.size()-1);
    }
};

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        istringstream is(S);
        string str;
        string ans = "";
        int pos = 1;
        while(getline(is, str, ' ')){
            if(vowels.find(str[0]) != vowels.end()) ans += str+"ma"+string(pos, 'a')+" ";
            else ans += str.substr(1)+string(1, str[0])+"ma"+string(pos, 'a')+" ";
            pos++;
        }
        ans.pop_back();
        return ans;
    }
};