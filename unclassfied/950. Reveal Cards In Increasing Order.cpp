class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), [](int a, int b){return a>b;});
        deque<int> q(deck.begin(), deck.end());
        deque<int> ans;
        ans.push_front(q.front()); q.pop_front();
        while(q.empty() == false){
            auto back = ans.back(); ans.pop_back();
            ans.push_front(back);
            ans.push_front(q.front());
            q.pop_front();
        }
        return vector<int>(ans.begin(), ans.end());
    }
};