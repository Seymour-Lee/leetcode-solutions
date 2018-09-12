class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<pair<Tweet *, Tweet *>> h;
        for(auto &u: followings[userId]){
            auto &t = tweets[u];
            if(t.size() > 0)
                h.emplace_back(t.data(), t.data()+t.size()-1);
        }
        auto &t = tweets[userId];
        if(t.size() > 0)
            h.emplace_back(t.data(), t.data()+t.size()-1);
        auto f = [](const pair<Tweet *, Tweet *> &a, const pair<Tweet *, Tweet *> &b){return a.second->time < b.second->time;};
        make_heap(h.begin(), h.end(), f);
        for(int i = 0; i < 10 && h.empty() == false; i++){
            pop_heap(h.begin(), h.end(), f);
            auto &hb = h.back();
            ans.push_back(hb.second->id);
            if(hb.first == hb.second--)
                h.pop_back();
            else
                push_heap(h.begin(), h.end(), f);
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followings[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
    
private:
    struct Tweet{
        int time;
        int id;
        Tweet(int _time, int _id): time(_time), id(_id){}
    };
    
    map<int, vector<Tweet>> tweets;
    map<int, set<int>> followings;
    int time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */