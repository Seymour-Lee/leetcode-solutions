class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1000000000 + 7;
        set<int> xs;
        xs.insert(0);
        for (auto r : rectangles) xs.insert(r[0]), xs.insert(r[2]);
        vector<int> x(xs.begin(), xs.end());
        unordered_map<int, int> xval2idx;
        for (int i = 0; i < x.size(); ++i) xval2idx[x[i]] = i;
        
        vector<int> count(x.size(), 0);
        vector<vector<int>> lines;
        for (auto r : rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            lines.push_back({y1, x1, x2, 1});
            lines.push_back({y2, x1, x2, -1});
        }
        sort(lines.begin(), lines.end());
        long long yprev = 0, xlen = 0, ans = 0;
        for (auto l : lines) {
            long long  y = l[0], x1 = l[1], x2 = l[2], sig = l[3];
            ans = (ans + (y - yprev) * xlen) % mod;
            yprev = y;
            for (int i = xval2idx[x1]; i < xval2idx[x2]; i++)
                count[i] += sig;
            xlen = 0;
            for (int i = 0; i < x.size(); ++i) {
                if (count[i] > 0)
                    xlen += x[i + 1] - x[i];
            }
        }
        return ans;
    }
};