class Twitter {
private:
    int cnt;
    unordered_map<int, int> clock_cnt;
    unordered_map<int, unordered_set<int>> tweeter_follow_list;
    unordered_map<int, unordered_set<int>> tweeter_post_list;
    unordered_map<int, vector<int>> tweeter_timeline;    
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        cnt = 0;
        
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        clock_cnt[tweetId] = cnt++;
        tweeter_post_list[userId].insert(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */

    vector<int> getNewsFeed(int userId) {
        vector<int> selected_list;
        for(auto &a : tweeter_follow_list[userId]){
            for(auto &b : tweeter_post_list[a]){
                selected_list.push_back(b);
            }
        }
        for(auto &a : tweeter_post_list[userId]){
            selected_list.push_back(a);
        }
        vector<pair<int, int>> sorted_waited;
        for(int i = 0; i < selected_list.size(); i++){
            pair<int, int> tmp;
            tmp.first = clock_cnt[selected_list[i]];
            tmp.second = selected_list[i];
            sorted_waited.push_back(tmp);
        }
        std::sort(sorted_waited.begin(), sorted_waited.end(), 
          [=](std::pair<int, int>& a, std::pair<int, int>& b) { return a.first > b.first; });
        
        vector<int> res;
        for(auto &a : sorted_waited){
            res.push_back(a.second);
        }
        
        if(res.size() <= 10)
            return res;
        
        vector<int> res_10;
        for(int i = 0; i < 10; i++){
            res_10.push_back(res[i]);
        }
        return res_10;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        tweeter_follow_list[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        if(!tweeter_follow_list.count(followerId))
            return;        
        for(unordered_set<int> :: iterator it = tweeter_follow_list[followerId].begin(); it != tweeter_follow_list[followerId].end(); ){
            if((*it) == followeeId){
                it = tweeter_follow_list[followerId].erase(it);
                break;
            }else
                it++;
        }
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */