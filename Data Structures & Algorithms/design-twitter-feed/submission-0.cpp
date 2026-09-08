class Twitter {
public:
    int time = 0;

    unordered_map<int, vector<pair<int, int>>> userTweets;

    unordered_map<int, unordered_set<int>> following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time, tweetId});
        time++;
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxHeap;

        for( auto& tweet : userTweets[userId])
        {
            maxHeap.push(tweet);
        }

        for(int followeeId : following[userId])
        {
            for(auto& tweet : userTweets[followeeId])
            {
                maxHeap.push(tweet);
            }
        }

        int i = 0;
        vector<int> feed;
        while(!maxHeap.empty() && i<10)
        {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
            i++;
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        return;
    }
};
