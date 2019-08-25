class Trie{
public:
    Trie(){
        value = -1;
    }
    
    bool insert(vector<string> &strs, int val){
        auto node = this;
        for(int i = 0; i < strs.size()-1; i++){
            string str = strs[i];
            if(node->a2c.find(str) == node->a2c.end()) return false;
            node = node->a2c[str];
        }
        if(node->a2c.find(strs.back()) != node->a2c.end()) return false;
        node->a2c[strs.back()] = new Trie();
        node = node->a2c[strs.back()];
        node->value = val;
        return true;
    }
    
    int search(vector<string> &strs){
        auto node = this;
        for(auto str: strs){
            if(node->a2c.find(str) == node->a2c.end()) return -1;
            node = node->a2c[str];
        }
        return node->value;
    }
    
private:
    unordered_map<string, Trie *> a2c;
    int value;
};

class FileSystem {
public:
    FileSystem() {
        trie = new Trie();
        vector<string> strs = {""};
        trie->insert(strs, -1);
    }
    
    bool create(string path, int value) {
        istringstream is(path);
        string str;
        vector<string> strs;
        while(getline(is, str, '/')) strs.push_back(str);
        return trie->insert(strs, value);
    }
    
    int get(string path) {
        istringstream is(path);
        string str;
        vector<string> strs;
        while(getline(is, str, '/')) strs.push_back(str);
        return trie->search(strs);
    }
    
private:
    Trie *trie;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */