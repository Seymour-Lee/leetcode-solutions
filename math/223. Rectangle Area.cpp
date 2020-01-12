class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total = (C-A) * (D-B) + (G-E) * (H-F);
        if(C<=E || G<=A || H<=B || D<=F) return total;
        vector<int> x{A, C, E, G};
        vector<int> y{B, D, F, H};
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return total - (x[2] - x[1]) * (y[2] - y[1]);
    }
};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long total = long(C-A) * (D-B) + long(G-E) * (H-F);
        if(C<=E || G<=A || H<=B || D<=F) return total;
        vector<long long> x{A, C, E, G};
        vector<int> y{B, D, F, H};
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return total - (x[2] - x[1]) * (y[2] - y[1]);
    }
};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long total = long(C-A) * (D-B) + long(G-E) * (H-F);
        if(C<=E || G<=A || H<=B || D<=F) return total;
        vector<long long> x{A, C, E, G};
        vector<int> y{B, D, F, H};
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return total - (x[2] - x[1]) * (y[2] - y[1]);
    }
};