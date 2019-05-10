class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        string result;
        int re_a, re_b;
        int im_a, im_b;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == '+'){
                re_a = atoi(a.substr(0, i).c_str());
                im_a = atoi(a.substr(i+1, a.size()-i-1-1).c_str());
                break;
            }
        }
        for(int i = 0; i < a.size(); i++){
            if(b[i] == '+'){
                re_b = atoi(b.substr(0, i).c_str());
                im_b = atoi(b.substr(i+1, b.size()-i-1-1).c_str());
                break;
            }
        }
        result = to_string(re_a*re_b - im_a*im_b) + "+" 
                +to_string(re_a*im_b + re_b*im_a) + "i";
        return result;
    }
};