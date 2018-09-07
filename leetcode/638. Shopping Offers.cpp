void operator+=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        a[i] += b[i];
}

void operator-=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        a[i] -= b[i];
}

bool operator<(const vector<int> &a, const int &n) {
    for (int i : a)
        if (i < n)
            return true;
    return false;
}

int operator*(const vector<int> &a, const vector<int> &b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] * b[i];
    return res;
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
        if(needs < 0) return INT_MAX;
        int result = cost + needs * price;
        for(auto &offer: special){
            if(cost + offer.back() >= result) continue;
            needs -= offer;
            result = min(result, shoppingOffers(price, special, needs, cost+offer.back()));
            needs += offer;
        }
        return result;
    }
};