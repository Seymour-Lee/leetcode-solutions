class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.size() == 0 || B.size() == 0) return {};
        vector<vector<int>> ans(A.size(), vector<int>(B[0].size(), 0));
        map<int, vector<int> > colIndToRowIndForA;
        for(int i=0; i<A.size(); i++)
            for(int j=0; j<A[0].size(); j++){
                if(A[i][j]!=0) {
                    if( colIndToRowIndForA.find(j) == colIndToRowIndForA.end() )
                        colIndToRowIndForA[j] = vector<int>();
                    colIndToRowIndForA[j].push_back(i);
                }
            }
        
        map<int, vector<int> > rowIndToColIndForB;
        for(int i=0; i<B.size(); i++)
            for(int j=0; j<B[0].size(); j++){
                if(B[i][j]!=0) {
                    if( rowIndToColIndForB.find(i) == rowIndToColIndForB.end() )
                        rowIndToColIndForB[i] = vector<int>();
                    rowIndToColIndForB[i].push_back(j);
                }
            }
        
        for(auto colRowA : colIndToRowIndForA) {
            int common = colRowA.first;
            
            if(rowIndToColIndForB.find(common) != rowIndToColIndForB.end() ) {
                vector<int> rowsA = colRowA.second;
                vector<int> colsB = rowIndToColIndForB[common];   
                
                for(auto a: rowsA) {
                    for(auto b: colsB) {
                        ans[a][b] += A[a][common]*B[common][b];
                    }
                }
            }
        }
        
        return ans;
    }
};