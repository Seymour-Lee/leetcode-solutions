class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name == "") return true;
        if(typed == "") return false;
        if(name.size() > typed.size()) return false;
        for(decltype(name.size()) i = 0, j = 0; i < name.size(); i++, j++){
            while(j < typed.size() && name[i] != typed[j]) j++;
            if(j == typed.size()) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while(i < name.size() && j < typed.size()){
            if(name[i] == typed[j]) i++, j++;
            else j++;
        }
        return i == name.size();
    }
};