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