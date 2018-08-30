class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 0) return 0;
        if(position.size() == 1) return 1;
        int result = 0;
        vector<Car> cars;
        for(int i = 0; i < position.size(); i++)
            cars.push_back(Car(position[i], 
                               (double)(target-position[i]) / speed[i]));
        sort(cars.begin(), cars.end(), 
             [](Car a, Car b){return a.position < b.position;});
        for(int i = cars.size()-1; i > 0; i--){
            if(cars[i].arrive < cars[i-1].arrive) result++;
            else cars[i-1].arrive = cars[i].arrive;
        }
        return result + 1;
    }
    
private:
    struct Car{
        int position;
        double arrive;
        Car(int p, double a): position(p), arrive(a){}
    };
};