class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size() && n; i++){
            if(i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            else if(i == flowerbed.size()-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            else if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }
};

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size() && n; i++) if(flowerbed[i] == 0){
            int prev = (i == 0? 0: flowerbed[i-1]);
            int next = (i == flowerbed.size()-1? 0: flowerbed[i+1]);
            if(prev == 0 && next == 0) flowerbed[i] = 1, n--;
        }
        return n == 0;
    }
};