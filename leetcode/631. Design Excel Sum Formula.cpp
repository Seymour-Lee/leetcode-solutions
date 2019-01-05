class Excel {
public:
    Excel(int H, char W) {
        offset = 'A';
        this->H = H;
        this->W = W - offset + 1;
        mp.clear();
        dict = vector<vector<int>>(H, vector<int>(W, 0));
    }
    
    void set (int r, char c, int v) {
        int k = (r << 10) + c;
        dict[r - 1][c - offset] = v;
        mp.erase(k);
    }
    
    int get (int r, char c) {
        int k = (r << 10) + c;
        if (mp.find(k) == mp.end())
            return dict[r - 1][c - offset];
        return get_cells(mp[k]);
    }
    
    int sum (int r, char c, vector<string> strs) {
        int k = (r << 10) + c;
        dict[r - 1][c - offset] = get_cells(strs);
        mp[k] = strs;
        return dict[r - 1][c - offset];
    }
    
    int get_cells(vector<string> &strs) {
        int res = 0;
        for (auto s : strs) {
            if (s.find(':')  == -1)
                res += get_cell(s);
            else
                res += get_cell_range(s);
        }
        return res;
    }
    
    int get_cell(string &cell) {
        int r = 0, idx = 0;
        char c = cell[idx++];
        while (idx < cell.length())
            r = 10 * r + cell[idx++] - '0';
        return get(r, c);
    }
    
    int get_cell_range(string &cell_range) {
        int rs = 0, re = 0, idx = 0, res = 0;
        char cs, ce;
        
        int seg = cell_range.find(':');
        cs = cell_range[idx++];
        while (idx < seg)
            rs = 10 * rs + cell_range[idx++] - '0';
        
        idx++;
        ce = cell_range[idx++];
        while (idx < cell_range.length())
            re = 10 * re + cell_range[idx++] - '0';
        
        for (int r = rs; r <= re; r++) {
            for (char c = cs; c <= ce; c++) {
                res += get(r, c);
            }
        }
        return res;
    }

private:
    vector<vector<int>> dict;
    int offset, H, W;
    unordered_map<int, vector<string>> mp;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */