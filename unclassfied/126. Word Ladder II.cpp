class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //this is the graph we'll be building
        unordered_map<string,pair<int,vector<string> > > graph;
        
        //dictionary of words <=> wordList
        unordered_set<string> dict;
        
        //the resultint lists
        vector<vector<string> > result;
        
        for(auto &s : wordList){
            dict.insert(s);    
        }
        
        deque<pair<string,int> > q;
        graph[beginWord].first = 0;
        graph[beginWord].second.push_back("");
        q.emplace_back(beginWord,1);
        
        //Perform a BFS - in each iteration we look at all words that could be formed from the current word
        //by switching letters. For each such word, if this is the first time we've seen it then we add it to the queue,
        //But regardless we look at it in the graph and if the count to reach that word is <= then the current count of the word
        //we add the generating word to this word's adjency list
        while(!q.empty()){
            auto front = q.front();
            string f = front.first;
            int count = front.second;
            q.pop_front();
            
            for(int i = 0; i < f.size(); ++i){
                string temp = f;
                for(char j = 'a'; j <= 'z'; ++j){
                    temp[i] = j;
                    
                    if(dict.find(temp) != dict.end()){
                        if(graph.find(temp) == graph.end()){
                            q.emplace_back(temp,count + 1);
                        }
                        
                        if(graph.find(temp) == graph.end() || 
                           graph[temp].first >= count){       
                             graph[temp].first = count;
                             graph[temp].second.push_back(f);
                        }
                    }
                }
            }
        }
        
        vector<string> tres;        
        getAllResults(graph,endWord,tres,result);
        return result;
    }
    
private:
    //traverses the graph from endWord to the begining (indicated by the empty word "")
    //and adds the words along the chain to the final list
    void getAllResults(unordered_map<string,pair<int,vector<string> > > &graph,
                       const string &word,
                       vector<string> tres,
                       vector<vector<string> > &result){
        if(word == ""){
            if(tres.empty() == false){
                //the words are reversed since we started from endWord
                reverse(tres.begin(),tres.end());
                result.push_back(tres);
            }
            
            return;
        }
        
        tres.push_back(word);
        for(const auto &w : graph[word].second){
            getAllResults(graph,w,tres,result);
        }
    }
};