class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(version1.size() || version2.size()){
            string sub1 = getSub(version1);
            string sub2 = getSub(version2);
            int num1 = stoi(sub1);
            int num2 = stoi(sub2);
            if(num1 != num2){
                return num1 < num2? -1: 1;
            }
            version1 = version1 == "" || sub1 == version1? "": 
                       version1.substr(sub1.size()+1, 
                                       version1.size()-sub1.size()-1);
            version2 = version2 == "" || sub2 == version2? "": 
                       version2.substr(sub2.size()+1, 
                                       version2.size()-sub2.size()-1);
        }
        return 0;
    }
    
private:
    string getSub(string str){
        if(str.size() == 0 || str[0] == '.') return "0";
        int i = 0;
        while(i < str.size() && str[i] != '.') i++;
        return i == str.size()? str: str.substr(0, i);
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1, vec2;
        istringstream is(version1);
        string str = "";
        while(getline(is, str, '.')) vec1.push_back(stoi(str));
        is = istringstream(version2);
        while(getline(is, str, '.')) vec2.push_back(stoi(str));
        for(int i = 0; i < vec1.size() || i < vec2.size(); i++){
            int one = i < vec1.size()? vec1[i]: 0;
            int two = i < vec2.size()? vec2[i]: 0;
            if(one > two) return 1;
            if(one < two) return -1;
        }
        return 0;
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a, b;
        istringstream is(version1);
        string str;
        while(getline(is, str, '.')) a.push_back(stoi(str));
        is = istringstream(version2);
        while(getline(is, str, '.')) b.push_back(stoi(str));
        while(a.size() && a.back() == 0) a.pop_back();
        while(b.size() && b.back() == 0) b.pop_back();
        return a > b? 1: (a < b? -1: 0); 
    }
};