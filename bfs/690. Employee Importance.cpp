/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.size() == 0) return 0;
        int result = 0;
        map<int, pair<int, vector<int>>> table;
        for(auto employee: employees) table[employee->id] = pair<int, vector<int>>(employee->importance, employee->subordinates);
        if(table.find(id) == table.end()) return 0;
        queue<int> q;
        q.push(id);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            pair<int, vector<int>> info = table[cur];
            result = result + info.first;
            for(auto e: info.second) q.push(e);
        }
        return result;
    }
};

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> a2b;
        unordered_map<int, int> a2v;
        for(auto e: employees) a2b[e->id] = e->subordinates, a2v[e->id] = e->importance;
        int ans = 0;
        queue<int> q;
        q.push(id);
        while(q.empty() == false){
            auto a = q.front(); q.pop();
            ans += a2v[a];
            for(auto b: a2b[a]) q.push(b);
        }
        return ans;
    }
};