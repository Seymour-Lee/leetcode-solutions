class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int n = persons.size();
        int lead = -1;
        map<int, int> count;
        for(int i = 0; i < n; i++) t2p[times[i]] = persons[i];
        for(auto it: t2p){
            if(++count[it.second] >= count[lead]) lead = it.second;
            t2p[it.first] = lead;
        }
    }
    
    int q(int t) {
        return (--t2p.upper_bound(t))->second;
    }
    
private:
    map<int, int> t2p;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */