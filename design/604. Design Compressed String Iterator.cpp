class StringIterator {
public:
    StringIterator(string compressedString) {
        for(int i = 0; i < compressedString.size(); ){
            char ch = compressedString[i++];
            int j = i+1;
            while(isdigit(compressedString[j])) j++;
            int num = stoi(compressedString.substr(i, j-i));
            i = j;
            qch2num.push({ch, num});
        }
    }
    
    char next() {
        if(hasNext() == false) return ' ';
        char ans;
        ans = qch2num.front().first;
        if(--qch2num.front().second == 0) qch2num.pop();
        return ans;
    }
    
    bool hasNext() {
        return qch2num.empty() == false;
    }
    
private:
    queue<pair<char, int>> qch2num;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

class StringIterator {
public:
    StringIterator(string compressedString) {
        for(int i = 0; i < compressedString.size(); ){
            char ch = compressedString[i++];
            int j = i+1;
            while(isdigit(compressedString[j])) j++;
            int num = stoi(compressedString.substr(i, j-i));
            i = j;
            qch2num.push({ch, num});
        }
    }
    
    char next() {
        if(hasNext() == false) return ' ';
        char ans;
        ans = qch2num.front().first;
        if(--qch2num.front().second == 0) qch2num.pop();
        return ans;
    }
    
    bool hasNext() {
        return qch2num.empty() == false;
    }
    
private:
    queue<pair<char, int>> qch2num;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */