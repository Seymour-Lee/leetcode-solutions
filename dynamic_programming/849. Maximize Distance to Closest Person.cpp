class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int longest = 0;
        int i, j;
        for(i = 0; i < seats.size() && seats[i] != 1; i++);
        longest = max(longest, i);
        for(j = i + 1; i < seats.size() && j < seats.size(); j++){
            if(seats[j]){
                int seat = (i + j) / 2;
                int dis = min(seat-i, j-seat);
                if(dis > longest){
                    longest = dis;
                }
                i = j;
            }
        }
        if(j-i-1 > longest) longest = j-1-i;
        return longest;
    }
};

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> l(seats.size(), INT_MIN/2);
        vector<int> r(seats.size(), INT_MAX/2);
        for(int i = 0, prev = INT_MIN/2; i < seats.size(); i++){
            if(seats[i] == 1) l[i] = 0, prev = i;
            else l[i] = prev;
        }
        for(int i = seats.size()-1, prev = INT_MAX/2; i >= 0; i--){
            if(seats[i] == 1) r[i] = 0, prev = i;
            else r[i] = prev;
        }
        int ans = 0;
        for(int i = 0; i < seats.size(); i++) if(seats[i] == 0) {
            ans = max(ans, min(i-l[i], r[i]-i));
        }
        return ans;
    }
};