class Solution {
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4));
        int r = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 3200 != 0));
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);
        unordered_map<string, int> m2d = {
            {"01", 0},
            {"02", 31},
            {"03", 59+r},
            {"04", 90+r},
            {"05", 120+r},
            {"06", 151+r},
            {"07", 181+r},
            {"08", 212+r},
            {"09", 243+r},
            {"10", 273+r},
            {"11", 304+r},
            {"12", 334+r},
        };
        return m2d[month] + stoi(day);
    }
    
};