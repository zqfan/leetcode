class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """

class Trie(object):

    def __init__(self):
        self.root = {None: 1}

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        cur = self.root
        for char in word:
            cur[char] = cur.get(char, {})
            cur = cur[char]
        cur[None] = 1

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        cur = self.root
        for char in word:
            if char not in cur:
                return False
            cur = cur[char]
        return None in cur

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        cur = self.root
        for char in prefix:
            if char not in cur:
                return False
            cur = cur[char]
        return True

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")

trie = Trie()
trie.insert("somestring")
print trie.search("key")
print trie.search("somestring")
print trie.startsWith("some")
print trie.search("some")

# 14 / 14 test cases passed.
# Status: Accepted
# Runtime: 178 ms
# 98.02%
