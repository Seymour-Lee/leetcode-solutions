class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if(input.size() == 0) return result;
        if(input.find('+') == string::npos && 
           input.find('-') == string::npos &&
           input.find('*') == string::npos){
            result.push_back(stoi(input));
            return result;
        }
        for(decltype(input.size()) i = 0; i != input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i+1));
                for(auto l: left){
                    for(auto r: right){
                        result.push_back(op2func[input[i]](l, r));
                    }
                }
            }
        }
        return result;
    }
    
private:
    map<char, int(*)(int, int)> op2func = {
        {'+', [](int a, int b){return a+b;}},
        {'-', [](int a, int b){return a-b;}},
        {'*', [](int a, int b){return a*b;}}};
};

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        if(input == "") return ans;
        if(input.find('+') == string::npos &&
           input.find('-') == string::npos &&
           input.find('*') == string::npos){
            ans.push_back(stoi(input));
        }
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i+1));
                for(auto l: left) for(auto r: right) ans.push_back(op2func[input[i]](l, r));
            }
        }
        return ans;
    }
    
private:
    unordered_map<char, int(*)(int, int)> op2func = {
        {'+', [](int a, int b){return a+b;}},
        {'-', [](int a, int b){return a-b;}},
        {'*', [](int a, int b){return a*b;}},
    };
    
    
};

class Solution {
public:
    vector<int> diffWaysToCompute(string str) {
        if(str.size() == 0) return {};
        vector<int> ans;
        if(str.find('+') == string::npos &&
           str.find('-') == string::npos &&
           str.find('*') == string::npos) return {stoi(str)};
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
                auto l = diffWaysToCompute(str.substr(0, i));
                auto r = diffWaysToCompute(str.substr(i+1));
                for(auto a: l) for(auto b: r) ans.push_back(op2func[str[i]](a, b));
            }
        }
        return ans;
    }
    
private:
    unordered_map<char, int(*)(int, int)> op2func = {
        {'+', [](int a, int b){return a+b;}},
        {'-', [](int a, int b){return a-b;}},
        {'*', [](int a, int b){return a*b;}},
    };
};