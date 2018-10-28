class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        for(auto email: emails){
            istringstream is = istringstream(email);
            string str = "", local = "", domain = "";
            getline(is, str, '@'); getline(is, domain, '@');
            for(auto c: str){
                if(c == '+') break;
                if(c == '.') continue;
                local += c;
            }
            unique.insert(local+domain);
        }
        return unique.size();
    }
};