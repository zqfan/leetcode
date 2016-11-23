class WordDictionary(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.wordlength = [set()]
        self.stats = []

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        while len(word) >= len(self.wordlength):
            self.wordlength.append(set())
        if word in self.wordlength[len(word)]:
            return
        self.wordlength[len(word)].add(word)
        for i, c in enumerate(word):
            if len(self.stats) < i+1:
                self.stats.append([])
                for _ in xrange(26):
                    self.stats[-1].append(set())
            idx = ord(c) - ord('a')
            self.stats[i][idx].add(word)

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        if len(word) >= len(self.wordlength):
            return False
        if word.find('.') == -1:
            return word in self.wordlength[len(word)]
        res = None
        for i, c in enumerate(word):
            if c != '.':
                if res is None:
                    res = self.wordlength[len(word)] & self.stats[i][ord(c)-ord('a')]
                else:
                    res &= self.stats[i][ord(c)-ord('a')]
        if res is None:
            res = self.wordlength[len(word)]
        for w in res:
            if len(w) == len(word):
                return True
        return False

# Your WordDictionary object will be instantiated and called as such:
# wordDictionary = WordDictionary()
# wordDictionary.addWord("word")
# wordDictionary.search("pattern")

w = WordDictionary()
w.addWord('a')
w.addWord('ab')
print w.search('a')
print w.search('a.')
print w.search('ab')
print w.search('.a')
print w.search('.b')
print w.search('ab.')
print w.search('.')
print w.search('..')
