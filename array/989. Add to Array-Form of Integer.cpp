class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int K) {
        vector<int> k;
        while(K) k.push_back(K % 10), K /= 10;
        reverse(a.begin(), a.end());
        vector<int> ans;
        int i = 0;
        int c = 0;
        while(i < a.size() || i < k.size()){
            int aa = i < a.size()? a[i]: 0;
            int kk = i < k.size()? k[i]: 0;
            ans.push_back((aa+kk+c)%10);
            c = (aa+kk+c)/10;
            i++;
        }
        if(c) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int K) {
        vector<int> k;
        while(K) k.push_back(K % 10), K /= 10;
        reverse(a.begin(), a.end());
        vector<int> ans;
        int i = 0;
        int c = 0;
        while(i < a.size() || i < k.size()){
            int aa = i < a.size()? a[i]: 0;
            int kk = i < k.size()? k[i]: 0;
            ans.push_back((aa+kk+c)%10);
            c = (aa+kk+c)/10;
            i++;
        }
        if(c) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};