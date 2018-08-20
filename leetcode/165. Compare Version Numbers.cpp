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