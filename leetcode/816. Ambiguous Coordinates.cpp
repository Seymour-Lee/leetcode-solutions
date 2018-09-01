class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        S = S.substr(1, S.size()-2);
        vector<string> result;
        if(S.size() < 2) return result;
        for(decltype(S.size()) i = 1; i != S.size(); i++){
            string a = S.substr(0, i);
            string b = S.substr(i);
            if(valid(a, false)){
                if(valid(b, false)) result.push_back("(" + a + ", " + b + ")");
                for(decltype(b.size()) j = 1; j != b.size(); j++){
                    if(valid(b.substr(0, j) + "." + b.substr(j), false)){
                        result.push_back("(" + a + ", " 
                                         + b.substr(0, j) + "." 
                                         + b.substr(j) +")");
                    }
                }
            }
            if(valid(b, false)){
                for(decltype(a.size()) j = 1; j != a.size(); j++){
                    if(valid(a.substr(0, j) + "." + a.substr(j), false)){
                        result.push_back("(" + a.substr(0, j) + "." 
                                         + a.substr(j) + ", " 
                                         + b +")");
                    }
                }
            }
            for(decltype(a.size()) j = 1; j != a.size(); j++){
                string astr = a.substr(0, j) + "." + a.substr(j);
                for(decltype(b.size()) j = 1; j != b.size(); j++){
                    string bstr = b.substr(0, j) + "." + b.substr(j);
                    if(valid(astr, false) && valid(bstr, false)){
                        result.push_back("(" + astr + ", " + bstr + ")");
                    }
                }
            }
        }
        return result;
    }
    
private:
    bool valid(string str, bool mantissa){
        if(str == "") return false;
        if(str.find('.') == string::npos){
            if(mantissa == false && str.size() > 1 && str[0] == '0') 
                return false;
            if(mantissa == true && (stoi(str) == 0 || str.back() == '0')) 
                return false;
            return true;
        }
        else{
            string a, b;
            decltype(str.size()) idx = 0;
            while(str[idx] != '.') idx++;
            return valid(str.substr(0, idx), false) && 
                valid(str.substr(idx+1), true);
        }
    }
};