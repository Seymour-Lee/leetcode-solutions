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