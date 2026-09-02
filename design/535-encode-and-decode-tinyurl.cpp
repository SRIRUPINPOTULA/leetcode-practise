// 535. Encode and Decode TinyURL
// https://leetcode.com/problems/encode-and-decode-tinyurl/
// Difficulty: Medium
// Topics: Hash Table, String, Design, Hash Function
//
// TinyURL is a URL shortening service where you enter a URL such as
// https://leetcode.com/problems/design-tinyurl and it returns a short URL such
// as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a
// tiny URL. There is no restriction on how your encode/decode algorithm should
// work. You just need to ensure that a URL can be encoded to a tiny URL and the
// tiny URL can be decoded to the original URL.
//
// Implement the Solution class:
//   Solution() Initializes the object of the system.
//   String encode(String longUrl) Returns a tiny URL for the given longUrl.
//   String decode(String shortUrl) Returns the original long URL for the given
//     shortUrl. It is guaranteed that the given shortUrl was encoded by the
//     same object.

// Approach: 1
class Solution {
private:
    unordered_map<string, string>decoder;
    string totalChars = "abcdefghijklmnopqrsABCDEFGHIJKLMNOPQRSRTUVWXYZ0123456789";
public:
    Solution(){
        
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encoder = "";
        for(int i=0; i<6; i++)
        {
            encoder = encoder + totalChars[rand()%totalChars.size()];
        }
        decoder[encoder] = longUrl;
        return encoder;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoder[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


// Approach 2: 
class Solution {
private:
    unordered_map<string, string>decoder;
    int counter = 0;
public:
    Solution(){
        counter = 0;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string res = to_string(counter);
        decoder[res] = longUrl;
        counter+=1;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoder[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));