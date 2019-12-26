class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;    
        int n = status.size();
        // unordered_set<int> openBox;
        unordered_set<int> closedBox;
        unordered_set<int> ks;
        queue<int> q; // boxes to open
        status.push_back(1);
        candies.push_back(0);
        keys.push_back({});
        containedBoxes.push_back(initialBoxes);
        q.push(n);
        while(q.empty() == false){
            int size = q.size();
            // cout<<size<<" "<<ans<<endl;
            while(size--){
                auto b = q.front(); q.pop();
                // cout<<b<<endl;
                ans += candies[b];
                for(auto key: keys[b]) ks.insert(key);
                for(auto cb: containedBoxes[b]) closedBox.insert(cb);
            }
            vector<int> tod;
            // open boxes
            for(auto b: closedBox){
                if(status[b] == 1){
                    q.push(b);
                    tod.push_back(b);
                }
                else{
                    if(ks.find(b) != ks.end()){
                        tod.push_back(b);
                        ks.erase(b);
                        q.push(b);
                        status[b] = 1;
                    }
                }
            }
            // remove opened boxes
            for(auto b: tod) closedBox.erase(b);
        }
        return ans;
    }
};

for(box: boxToOpen){
    if()
}