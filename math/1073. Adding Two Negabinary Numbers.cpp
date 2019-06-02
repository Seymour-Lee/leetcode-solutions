class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int c1 = 0, c0 = 0;
        int i = arr1.size()-1, j = arr2.size()-1;
        while(i >= 0 || j >= 0){
            int a = (i >= 0? arr1[i]: 0);
            int b = (j >= 0? arr2[j]: 0);
            int sum = a+b+c0;
            int res = 0;
            if(sum == -2) res = 0, c0 = 1;
            if(sum == -1) res = 1, c0 = 1;
            if(sum == 0) res = 0, c0 = 0;
            if(sum == 1) res = 1, c0 = 0;
            if(sum == 2) res = 0, c0 = -1;
            if(sum == 3) res = 1, c0 = -1;
            
            // int res = (a+b+c0+c1)%2;
            // cout<<c1<<" "<<c0<<" "<<a<<" "<<b<<" "<<res<<endl;
            // if(a+b+c0+c1 == 4) c1 = c0, c0 = 0;
            // else if(a+b+c0+c1 == 3) c1 = c0, c0 = 1;
            // else if(a+b+c0+c1 == 2) c1 = c0, c0 = 1;
            // else c1 = c0, c0 = 0;
            ans.push_back(res);
            i--, j--;
        }
        // cout<<c1<<" "<<c0;
        // if(c1 == 0 && c0 == 1) ans.push_back(1);
        // else if(c1 == 1 && c0 == 0){
        //     ans.push_back(1); ans.push_back(1);
        // }
        // else if(c1 == 1 && c0 == 1){
        //     ans.push_back(0);ans.push_back(1); ans.push_back(1);
        // }
        if(c0 == -1){
            ans.push_back(1);
            c0 = 1;
        }
        if(c0 == 1){
            ans.push_back(1);
        }
        while(ans.size() > 1 && ans.back() == 0)ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};