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