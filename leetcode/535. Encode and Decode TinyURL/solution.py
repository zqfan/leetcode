class Codec:

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        short = self._base62(self.idx)
        self.cache[short] = longUrl
        self.idx += 1
        return self.url_prefix + short

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.cache[shortUrl[len(self.url_prefix):]]

    def _base62(self, n):
        n62 = ['0'] * 6
        i = 5
        while n > 0:
            n62[i] = charmap[n % 62]
            i -= 1
            n /= 62
        return ''.join(n62)

    charmap = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
    cache = {}
    idx = 0
    url_prefix = 'http://tinyurl.com/'
# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
