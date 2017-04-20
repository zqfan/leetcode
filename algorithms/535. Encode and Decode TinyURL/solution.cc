class Solution {
    string letters = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count = 0;
    map<string, string> mem;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = toBase62(count++);
        mem[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mem[shortUrl];
    }
    
    string toBase62(int n) {
        string b62(6, '0');
        int i = 0;
        while ( n > 0 ) {
            b62[i++] = letters[n % 62];
            n /= 62;
        }
        return b62;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
