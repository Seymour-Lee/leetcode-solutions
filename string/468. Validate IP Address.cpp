class Solution {
public:
    string validIPAddress(string IP) {
        istringstream is(IP);
        string t = "";
        int counter = 0;
        if(IP.find(':') == string::npos){
            while(getline(is, t, '.')){
                counter++;
                if(counter > 4 || t.empty() ||(t.size() > 1 && t[0] == '0')
                  || t.size() > 3) return "Neither";
                for(auto c: t) if(isdigit(c) == false) return "Neither";
                int val = stoi(t);
                if(val < 0 || val > 255) return "Neither";
            }
            return counter == 4 && IP.back() != '.'? "IPv4": "Neither";
        }
        else{
            while(getline(is, t, ':')){
                counter++;
                if(counter > 8 || t.empty() || t.size() > 4) return "Neither";
                for(auto c: t) 
                    if(!(c >= '0' && c <= '9') && 
                       !(c >= 'a' && c <= 'f') && 
                       !(c >= 'A' && c <= 'F')) 
                        return "Neither";
            }
            return counter == 8 && IP.back() != ':'? "IPv6": "Neither";
        }
    }
};

class Solution {
public:
    string validIPAddress(string IP) {
        istringstream is(IP);
        string t = "";
        int counter = 0;
        if(IP.find(':') == string::npos){
            while(getline(is, t, '.')){
                counter++;
                if(counter > 4 || t.empty() ||(t.size() > 1 && t[0] == '0')
                  || t.size() > 3) return "Neither";
                for(auto c: t) if(isdigit(c) == false) return "Neither";
                int val = stoi(t);
                if(val < 0 || val > 255) return "Neither";
            }
            return counter == 4 && IP.back() != '.'? "IPv4": "Neither";
        }
        else{
            while(getline(is, t, ':')){
                counter++;
                if(counter > 8 || t.empty() || t.size() > 4) return "Neither";
                for(auto c: t) 
                    if(!(c >= '0' && c <= '9') && 
                       !(c >= 'a' && c <= 'f') && 
                       !(c >= 'A' && c <= 'F')) 
                        return "Neither";
            }
            return counter == 8 && IP.back() != ':'? "IPv6": "Neither";
        }
    }
};