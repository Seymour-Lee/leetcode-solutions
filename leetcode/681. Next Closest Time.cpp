class Solution {
public:
    string nextClosestTime(string time) {
        time.erase(time.begin()+2);
        set<char> chars(time.begin(), time.end());
        string ans = getNext(time, chars);
        while(valid(ans) == false) ans = getNext(ans, chars);
        ans.insert(ans.begin()+2, ':');
        return ans;
    }
    
private:
    string getNext(string str, set<char> chars){
        for(auto i = 3; i >= 0; i--){
            auto itor = chars.find(str[i]);
            itor++;
            if(itor != chars.end()){
                str[i] = *itor;
                return str;
            }
            else{
                str[i] = *chars.begin();
            }
        }
        return str;
    }
    
    bool valid(string str){
        if((str[0]-'0')* 10+ str[1]-'0'< 24 &&
           (str[2]-'0')* 10+ str[3]-'0'< 60)
            return true;
        return false;
    }
};