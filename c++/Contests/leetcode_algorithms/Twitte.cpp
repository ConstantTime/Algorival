#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class Twitter {
public:
    /** Initialize your data structure here. */
    int time;
    unordered_map < int , priority_queue < pair < int , int > > > a;
    unordered_map < int , set < int > > id;
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time++;
        a[userId].push({time , tweetId});        
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue < pair < int , int > > b , temp;
        vector < int > ans;
        int cnt = 0;
        temp = a[userId];
        while(!temp.empty()) {
            b.push(temp.top());
            temp.pop();
        }
        for(auto j : id[userId]) {
            if(j == userId) continue;
            temp = a[j];
            while(!temp.empty()) {
                b.push(temp.top());
                temp.pop();
            }
        }
        while(cnt != 10 && !b.empty()) {
            ans.push_back(b.top().second);
            b.pop();
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        id[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        id[followerId].erase(followeeId);   
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);

   
    
    return 0;
}
