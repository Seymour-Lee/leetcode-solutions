class Solution {
public:
    int rotatedDigits(int N) {
        int result = 0;
        map<int, int> table;
        table[0] = 0; table[1] = 1; table[2] = 5; table[5] = 2; table[6] = 9; table[8] = 8; table[9] = 6;
        for(int i = 1; i <= N; i++){
            string cur = to_string(i);
            int rotated = 0;
            int j;
            for(j = 0; j < cur.size(); j++){
                int num = cur[j] - '0';
                if(num % 10 == 3 || num % 10 == 4 || num % 10 == 7) break;
                rotated = rotated * 10 + table[num];
            }
            if(j == cur.size() && rotated != i){
                result++;
            }
        }
        return result;
    }
};