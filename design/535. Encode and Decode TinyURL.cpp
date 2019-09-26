class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string hash;
        if(l2s.find(longUrl) == l2s.end()){
            for(int i = 0; i < 6; i++){
                hash.push_back(code[(rd() + i * i) % code.size()]);
            }
            l2s[longUrl] = hash;
            s2l[hash] = longUrl;
        }
        else{
            hash = l2s[longUrl];
        }
        return  "http://tinyurl.com/" + hash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size() != 25 || s2l.find(shortUrl.substr(19, 6)) == s2l.end()) return "";
        return s2l[shortUrl.substr(19, 6)];
    }
    
private:
    const string code = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    map<string, string> l2s;
    map<string, string> s2l;
    random_device rd;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

class Solution {
public:
     hash<string> t;
     map<string,string> h;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
               
        string l = to_string(t(longUrl));
        h[l] = longUrl; 
        
        return "http://tinyurl.com/" + l; 
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        string m = "http://tinyurl.com/";
       
        
        return h[shortUrl.substr(m.size())];
    }
};

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ans = "";
        for(int i = 0; i < len; i++) ans += code[rand()%code.size()];
        s2l[ans] = longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return s2l[shortUrl];
    }
    
private:
    string code = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> s2l;    
    int len = 6;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));