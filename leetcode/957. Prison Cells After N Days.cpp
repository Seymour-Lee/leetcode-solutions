class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<int, vector<int>> day2cell;
        set<vector<int>> seen;
        cells = nextday(cells);
        seen.insert(cells);
        day2cell[1] = cells;
        bool circle = false;
        for(int i = 2; i <= N; i++){
            cells = nextday(cells);
            if(seen.find(cells) != seen.end()){
                circle = true;
                break;
            }

            seen.insert(cells);
            day2cell[i] = cells;
        }
        if(circle){
            int n = seen.size();
            int day = ((N)%n);
            cells = day2cell[day == 0? n: day];
        }
        return cells;
    }
    
private:
    vector<int> nextday(vector<int> cells){
        vector<int> ans(8, 0);
        for(int i = 1; i < 7; i++){
            if(cells[i-1] == cells[i+1]) ans[i] = 1;
            else ans[i] = 0;
        }
        return ans;
    }
};