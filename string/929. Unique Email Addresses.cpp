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

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;
        for(auto e: emails){
            auto pos = e.find('@');
            string fake = e.substr(0, pos);
            string domain = e.substr(pos);
            string name = "";
            for(int i = 0; i < fake.size() && fake[i] != '+'; i++){
                if(fake[i] == '.') continue;
                name += fake[i];
            }
            ans.insert(name + domain);
        }
        return ans.size();
    }
};