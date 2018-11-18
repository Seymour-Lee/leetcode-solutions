class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int remain = A.size();
        while(remain > 1){
            int longest = INT_MIN;
            string ans = "";
            int a, b;
            for(int i = 0; i < remain; i++){
                for(int j = i+1; j < remain; j++){
                    auto p = overlap(A[i], A[j]);
                    string res = p.second;
                    int size = p.first;
                    if(longest < size){
                        longest = size;
                        ans = res;
                        a = j;
                        b = i;
                    }
                }
            }
            if(longest == INT_MIN){ // no overlap
                A[0] += A[remain-1];
            }
            else{ // have overlap
                A[a] = ans;
                A[b] = A[remain-1];
            }
            remain--;
        }
        return A.front();
    }
    
    pair<int, string> overlap(string a, string b){
        string ans = "";
        int longest = INT_MIN;
        for(int len = 1; len <= min(a.size(), b.size()); len++){
            // suffix a-b
            if(b.substr(0, len) == a.substr(a.size()-len, len)){
                if(len > longest){
                    ans = a+b.substr(len);
                    longest = len;
                }
            }
        }
        for(int len = 1; len <= min(a.size(), b.size()); len++){
            // prefix b-a
            if(a.substr(0, len) == b.substr(b.size()-len, len)){
                if(len > longest){
                    ans = b+a.substr(len);
                    longest = len;
                }
            }
        }
        
        return {longest, ans};
    }
};