class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        int start = str2int(ip);
        vector<string> ans;
        while(n) deal(ans, start, n);
        return ans;
    }
    
private:
    int str2int(string ip){
        istringstream is(ip);
        int a, b, c, d;
        char ch;
        is>>a>>ch>>b>>ch>>c>>ch>>d;
        return (a << 24) | (b << 16) | (c << 8) | d;
    }
    
    int getTrailingZero(int ip){
        if (ip == 0) return sizeof(int);
        int count = 0;
        while ((ip & 0x1) == 0){
            count ++;
            ip >>= 1;
        }
        return count;
    }
    
    void deal(vector<string> &result, int &startIp, int &number){
        int trailingZeros = getTrailingZero(startIp);
        int covered = 1 << trailingZeros;
        while (covered > number)
        {
            covered >>= 1;
            trailingZeros --;
        }

        char buf[200];
        sprintf(buf, "%d.%d.%d.%d/%d", (startIp >> 24) & 0xFF, (startIp >> 16) & 0xFF,
            (startIp >> 8) & 0xFF, startIp & 0xFF, 32 - trailingZeros);

        result.emplace_back(buf);
        number -= covered;
        startIp += covered;
    }
};

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        int start = str2int(ip);
        vector<string> ans;
        while(n) deal(ans, start, n);
        return ans;
    }
    
private:
    int str2int(string ip){
        istringstream is(ip);
        int a, b, c, d;
        char ch;
        is>>a>>ch>>b>>ch>>c>>ch>>d;
        return (a << 24) | (b << 16) | (c << 8) | d;
    }
    
    int getTrailingZero(int ip){
        if (ip == 0) return sizeof(int);
        int count = 0;
        while ((ip & 0x1) == 0){
            count ++;
            ip >>= 1;
        }
        return count;
    }
    
    void deal(vector<string> &result, int &startIp, int &number){
        int trailingZeros = getTrailingZero(startIp);
        int covered = 1 << trailingZeros;
        while (covered > number)
        {
            covered >>= 1;
            trailingZeros --;
        }

        char buf[200];
        sprintf(buf, "%d.%d.%d.%d/%d", (startIp >> 24) & 0xFF, (startIp >> 16) & 0xFF,
            (startIp >> 8) & 0xFF, startIp & 0xFF, 32 - trailingZeros);

        result.emplace_back(buf);
        number -= covered;
        startIp += covered;
    }
};