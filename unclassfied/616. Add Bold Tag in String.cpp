class Solution {
public:   
    struct comp{
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            return (a.first < b.first || (a.first == b.first && a.second < b.second));
        }
    }myComp;
    
    void findRanges(string s,vector<string>& dict,vector<pair<int,int>>& v){
        int n = dict.size();
        for(int i = 0;i < n;i++){
            int start = 0;
            int len = dict[i].size();
            int pos;
            while((pos = s.find(dict[i],start)) != std::string::npos){
                v.push_back(make_pair(pos,pos + len-1));
                if(len != 1)
                    start = pos + len - 1;
                else
                    start = pos + len;
            }
        }    
    }
    
    vector<pair<int,int>> mergeRanges(vector<pair<int,int>>& v){
        if(v.size() == 0) return v;
        sort(v.begin(),v.end(),myComp);
        vector<pair<int,int>> res;
        res.push_back(v[0]);
        for(int i = 1;i < v.size();i++){
            if(v[i].first <= res.back().second)
                res.back().second = max(res.back().second,v[i].second);
            else if(v[i].first == res.back().second + 1)
                res.back().second = v[i].second;
            else
                res.push_back(v[i]);
        }
        return res;
    }
    
    string addBoldTag(string s, vector<string>& dict) {
        if(dict.size() == 0 || s.length() == 0) return s;
        vector<pair<int,int>> v;
        findRanges(s,dict,v);
        v = mergeRanges(v);
        int offset = 0;
        for(int i = 0;i < v.size();i++){
            s.insert(v[i].second+1+offset,"</b>");
            s.insert(v[i].first + offset,"<b>");
            offset += 7;
        }
        return s;
    }
};