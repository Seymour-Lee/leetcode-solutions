// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 0;
        while(reader.get(r) < target) r = r * 2 + 1;
        while(reader.get(l) != INT_MAX && l <= r){
            int m = l + (r - l) / 2;
            int val = reader.get(m);
            if(val == target) return m;
            if(val < target) l = m + 1;
            else if(val > target) r = m - 1;
        }
        return -1;
    }
};

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = INT_MAX;
        while(l < r){
            int m = l + (r - l) / 2;
            int num = reader.get(m);
            if(num == INT_MAX || target <= num) r = m;
            else l = m+1;
        }
        return reader.get(l) == target? l: -1;
    }
};