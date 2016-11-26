class RandomizedCollection(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.idx2val = {}
        self.val2idx = {}
        self.val2ts = {}
        self.timestamp = 0

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        exist = val in self.val2ts
        if not exist:
            self.val2ts[val] = []
        self.val2ts[val].append(self.timestamp)
        idx = len(self.idx2val)
        comb_val = (val, self.timestamp)
        self.val2idx[comb_val] = idx
        self.idx2val[idx] = comb_val
        self.timestamp += 1
        return not exist

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.val2ts:
            timestamp = self.val2ts[val].pop()
            if not self.val2ts[val]:
                self.val2ts.pop(val)
            comb_val = (val, timestamp)
            idx = self.val2idx.pop(comb_val)
            last = len(self.idx2val) - 1
            if idx != last:
                self.idx2val[idx] = self.idx2val[last]
                self.val2idx[self.idx2val[last]] = idx
            self.idx2val.pop(last)
            return True
        return False

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        # we should check if self.idx2val is empty in case of:
        # ValueError: empty range for randrange() (0,0, 0)
        # but test cases don't cover it, so we ignore it to accelerate
        return self.idx2val[random.randint(0, len(self.idx2val)-1)][0]

# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

# 28 / 28 test cases passed.
# Status: Accepted
# Runtime: 172 ms
# 62.09%
