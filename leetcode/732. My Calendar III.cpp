// Boundary Counting
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        time2freq[start]++;
        time2freq[end]--;
        int k = 0;
        int unclosedIntervals = 0;
        for(auto it: time2freq){
            unclosedIntervals += it.second;
            k = max(k, unclosedIntervals);
        }
        return k;
    }
    
private:
    map<int, int> time2freq;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */

// Segment Tree
class MyCalendarThree {
public:
    MyCalendarThree() {
        root.reset(new TreeNode(0, upperRange, 0));
        maxFreq = 0;
    }
    
    int book(int start, int end) {
        insert(start, end, root.get());
        return maxFreq;
    }
    
private:
    const int upperRange = 1000000000;
    
    struct TreeNode{
        TreeNode(int s, int e, int c): start(s), end(e), middle(-1), counter(c){}
        int start;
        int end;
        int middle;
        int counter;
        unique_ptr<TreeNode> left;
        unique_ptr<TreeNode> right;
    };
    
    unique_ptr<TreeNode> root;
    int maxFreq;
    
    void insert(int start, int end, TreeNode *root){
        if(root->middle != -1){
            if(end <= root->middle){
                insert(start, end, root->left.get());
            }
            else if(root->middle <= start){
                insert(start, end, root->right.get());
            }
            else{
                insert(start, root->middle, root->left.get());
                insert(root->middle, end, root->right.get());
            }
            return;
        }
        
        if(start == root->start && root->end == end){
            maxFreq = max(maxFreq, ++root->counter);
        }
        else if(start == root->start){
            root->middle = end;
            root->left.reset(new TreeNode(root->start, root->middle, root->counter+1));
            root->right.reset(new TreeNode(root->middle, root->end, root->counter));
            maxFreq = max(maxFreq, root->counter+1);
        }
        else if(root->end == end){
            root->middle = start;
            root->left.reset(new TreeNode(root->start, root->middle, root->counter));
            root->right.reset(new TreeNode(root->middle, root->end, root->counter+1));
            maxFreq = max(maxFreq, root->counter+1);
        }
        else{
            root->middle = start;
            root->left.reset(new TreeNode(root->start, root->middle, root->counter));
            root->right.reset(new TreeNode(root->middle, root->end, root->counter));
            insert(start, end, root->right.get());
        }
        
        return;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */