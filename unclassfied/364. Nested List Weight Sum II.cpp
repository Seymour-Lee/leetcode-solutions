/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> depths;
        for(auto nl: nestedList) dfs(nl, 0, depths);
        int ans = 0;
        for(int i = depths.size()-1, level = 1; i >= 0; i--, level++)
            ans += depths[i]*level;
        return ans;
    }
    
private:
    void dfs(NestedInteger &nl, int depth, vector<int> &depths){
        if(depths.size() < depth+1) depths.push_back(0);
        if(nl.isInteger()){
            depths[depth] += nl.getInteger();
        }
        else{
            for(auto e: nl.getList()) dfs(e, depth+1, depths);
        }
    }
};