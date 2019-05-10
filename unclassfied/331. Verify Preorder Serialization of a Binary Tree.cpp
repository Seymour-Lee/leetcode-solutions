class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream is(preorder);
        string node = "";
        vector<string> stk;
        while(getline(is, node, ',')){
            stk.push_back(node);
            while(stk.size() >= 3 && stk[stk.size()-1] == "#"
               && stk[stk.size()-2] == "#" && stk[stk.size()-3] != "#"){
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back("#");
            }
        }
        return stk.size() == 1 && stk.back() == "#";
    }
};