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


int main()
{

    return 0;
}