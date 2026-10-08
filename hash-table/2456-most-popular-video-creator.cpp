// 2456. Most Popular Video Creator
// https://leetcode.com/problems/most-popular-video-creator/
// Difficulty: Medium
// Topics: Array, Hash Table, Sorting
//
// You are given two string arrays creators and ids, and an integer array views,
// all of length n. The ith video on a platform was created by creators[i], has
// an id of ids[i], and has views[i] views.
//
// The popularity of a creator is the sum of the number of views on all of the
// creator's videos. Find the creator with the highest popularity and the id of
// their most viewed video.
//   - If multiple creators have the highest popularity, find all of them.
//   - If multiple videos have the highest view count for a creator, find the
//     lexicographically smallest id.
//
// Note: It is possible for different videos to have the same id, meaning that
// ids do not uniquely identify a video. For example, two videos with the same
// ID are considered as distinct videos with their own viewcount.
//
// Return a 2D array of strings answer where answer[i] = [creatorsi, idi] means
// that creatorsi has the highest popularity and idi is the id of their most
// popular video. The answer can be returned in any order.

class Solution {
public:
    static bool help(pair<string, int>&a, pair<string, int>&b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }

    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>>res;
        int size = creators.size();
        unordered_map<string, long long>popularity;
        unordered_map<string, vector<pair<string, int>>>allVideos;
        long long maxPopular = 0;
        for(int i = 0; i<size; i++)
        {
            popularity[creators[i]] =  popularity[creators[i]] + views[i];
            maxPopular = max(maxPopular,  popularity[creators[i]]);
            allVideos[creators[i]].push_back({ids[i], views[i]});
        }

        unordered_set<string>popularCreator;
        for(auto a : popularity)
        {
            if(a.second == maxPopular)
                popularCreator.insert(a.first);
        }

        for(auto a : popularCreator)
        {
            vector<pair<string, int>>temp = allVideos[a];
            sort(temp.begin(), temp.end(), help);
            res.push_back({a, temp[0].first});
        }
        return res;
    }
};