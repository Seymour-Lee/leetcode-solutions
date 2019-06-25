class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minval = 256, maxval = 0.0, mean = 0.0, medi = 0.0, mode = 0.0;
        double sum = 0.0;
        int counter = 0;
        for(int i = 0; i < count.size(); i++){
            counter += count[i];
            sum += i*count[i];
            if(count[i]) minval = min((int)minval, i);
            if(count[i]) maxval = max((int)maxval, i);
            if(count[i] > count[mode]) mode = i;
        }
        int c = 0;
        cout<<counter<<endl;
        if(counter % 2 == 0){
            int p0 = counter / 2, p1 = counter/2+1;
            cout<<p0<<" "<<p1<<endl;
            for(int i = 0; i < count.size(); i++){
                c += count[i];
                if(c >= p0 && medi == 0){
                    medi += i;
                    cout<<i<<endl;
                }
                if(c >= p1){
                    medi += i;
                    cout<<i<<endl;
                    medi /= 2;
                    break;
                }
            }
        }
        else{
            int p = counter / 2;
            for(int i = 0; i < count.size(); i++){
                c += count[i];
                if(c >= p){
                    medi = i;
                    break;
                }
            }
            
        }
        mean = sum / counter;
        return {minval, maxval, mean, medi, mode};
    }
};