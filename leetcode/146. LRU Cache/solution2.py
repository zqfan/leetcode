class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        # [k1...kc]
        self.lru = collections.deque()
        # key: value
        self.kv = {}

    def get(self, key):
        """
        :rtype: int
        """
        if key not in self.kv:
            return -1
        self.lru.remove(key)
        self.lru.appendleft(key)
        return self.kv[key]

    def set(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        if key in self.kv:
            self.lru.remove(key)
        else:
            if len(self.kv) >= self.capacity:
                self.kv.pop(self.lru.pop())
        self.kv[key] = value
        self.lru.appendleft(key)
