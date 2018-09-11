class Solution {
public:
    string pushDominoes(string dominoes) {
        if(dominoes.size() <= 1) return dominoes;
        string ans = "";
        int l = 0, r = 0;
        while(l < dominoes.size() && dominoes[l] == '.') l++;
        if(l == dominoes.size()) return dominoes;
        if(dominoes[l] == 'R') ans += string(l, '.');
        else if(dominoes[l] == 'L') ans += string(l, 'L');
        r = l + 1;
        while(r < dominoes.size()){
            while(r < dominoes.size() && dominoes[r] == '.') r++;
            if(r == dominoes.size()) break;
            if(dominoes[l] == dominoes[r]) ans += string(r-l, dominoes[l]);
            else if(dominoes[l] == 'R' && dominoes[r] == 'L'){
                ans += "R" + string((r-l-1)/2, 'R');
                if((r-l-1) % 2 == 1) ans += ".";
                ans += string((r-l-1)/2, 'L');
            }
            else if(dominoes[l] == 'L' && dominoes[r] == 'R'){
                ans += "L" + string(r-l-1, '.');
            }
            l = r++;
        }
        if(dominoes[l] == 'L') ans += "L" + string(dominoes.size()-1-l, '.');
        else if(dominoes[l] == 'R') ans += string(dominoes.size()-l, 'R');
        return ans;
    }
};