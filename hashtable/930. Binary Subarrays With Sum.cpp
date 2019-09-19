class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if(A.size() == 0) return 0;
        int ans = 0;
        int i = 0, j = 0;
        int sum = A[0];
        while(i < A.size() &&j < A.size()){
            if(sum > S){
                i++, sum = A[i], j = i;
                continue;
            }
            while(j < A.size() && sum < S) j++, sum += A[j];
            if(j >= A.size()) break;
            int jj = j;
            while(jj < A.size()-1 && A[jj+1] == 0) jj++;
            int diff = jj-j+1;
            ans += diff;
            while(A[i] == 0 && i+1 <= j && i+1 < A.size() && A[i+1] == 0) ans += diff, i++;
            sum -= A[i], i++;
            if(i > j) j = i, sum = A[i];
        }
        return ans;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> sum2freq = {{0, 1}};
        int sum = 0, ans = 0;
        for(auto a: A){
            sum += a;
            ans += sum2freq[sum-S];
            sum2freq[sum]++;
        }
        return ans;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> counter(1, 0);
        for(auto a: A) counter.push_back(counter.back()+a);
        unordered_map<int, int> a2c;
        int ans = 0;
        for(auto c: counter){
            ans += a2c[c];
            a2c[c+S]++;
        }
        return ans;
    }
};