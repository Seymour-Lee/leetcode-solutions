// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int off = 0;
        while(off < n){
            int len = read4(buf+off);
            if(len == 0) break;
            off += len;
        }
        return min(off, n);
    }
};

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        while(ans < n){
            int num = read4(buf+ans);
            ans += num;
            if(num < 4) break;
        }
        return min(ans, n);
    }
};