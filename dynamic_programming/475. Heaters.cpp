class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int result = INT_MIN;
        vector<int> dist(houses.size(), INT_MAX);
        for(int i = 0, j = 0; i < houses.size() && j < heaters.size(); ){
            if(houses[i] <= heaters[j]) {
                dist[i] = heaters[j] - houses[i];
                i++;
            }
            else{
                j++;
            }
        }
        for(int i = houses.size()-1, j = heaters.size()-1; i >= 0 && j >= 0; ){
            if(houses[i] >= heaters[j]){
                dist[i] = min(dist[i], houses[i] - heaters[j]);
                i--;
            }
            else{
                j--;
            }
        }
        for(auto d: dist) result = max(result, d);
        return result;
    }
};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int result = INT_MIN;
        vector<int> dist(houses.size(), INT_MAX);
        for(int i = 0, j = 0; i < houses.size() && j < heaters.size(); ){
            if(houses[i] <= heaters[j]) {
                dist[i] = heaters[j] - houses[i];
                i++;
            }
            else{
                j++;
            }
        }
        for(int i = houses.size()-1, j = heaters.size()-1; i >= 0 && j >= 0; ){
            if(houses[i] >= heaters[j]){
                dist[i] = min(dist[i], houses[i] - heaters[j]);
                i--;
            }
            else{
                j--;
            }
        }
        for(auto d: dist) result = max(result, d);
        return result;
    }
};