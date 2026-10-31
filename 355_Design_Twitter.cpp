#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Sub-Optimal Sol
class Twitter {
    int time_stamp = 0;
    unordered_map<int, vector<pair<int, int>>> all_tweets;      // user, {time, tweet}
    unordered_map<int, unordered_set<int>> f_list;             // f -> {f1, f2, f3, ...}
public:
    Twitter(){}
    
    void postTweet(int userId, int tweetId) {
        all_tweets[userId].push_back({time_stamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto &t : all_tweets[userId]){
            pq.push(t);
        }
        for(auto &f : f_list[userId]){
            for(auto &t : all_tweets[f]){
                pq.push(t);
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId){
            f_list[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            f_list[followerId].erase(followeeId);
        }
    }
};

// Optimal Solution -> with k-way priority_queue
class Twitter {
    int time_stamp = 0;
    unordered_map<int, vector<pair<int, int>>> all_tweets;      // user, {time, tweet}
    unordered_map<int, unordered_set<int>> f_list;             // f -> {f1, f2, f3, ...}
public:
    Twitter(){}
    
    void postTweet(int userId, int tweetId) {
        all_tweets[userId].push_back({time_stamp++, tweetId});
    }
    
    // K-way implementation, keeping only the top-10 newest tweets into the Priority_Queue
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> pq;
        
        auto pushLatestTweet = [&](int uid){
            if(!all_tweets[uid].empty()){
                int lastIdx = all_tweets[uid].size() - 1;
                pq.push({all_tweets[uid][lastIdx].first, all_tweets[uid][lastIdx].second, uid, lastIdx});
            }
        };

        pushLatestTweet(userId);
        for(auto& f : f_list[userId]){
            pushLatestTweet(f);
        }

        while(!pq.empty() && ans.size() < 10){
            vector<int> curr = pq.top();
            pq.pop();
            ans.push_back(curr[1]);

            int uid = curr[2];
            int index = curr[3];
            if(index > 0){
                int nextIdx = index - 1;
                pq.push({all_tweets[uid][nextIdx].first, all_tweets[uid][nextIdx].second, uid, nextIdx});
            }
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId){
            f_list[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            f_list[followerId].erase(followeeId);
        }
    }
};

int main()
{

    return 0;
}