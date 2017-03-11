class DoubleLinkNode(object):
    def __init__(self, count=0):
        self.keys = set()
        self.count = count
        self.pre = None
        self.next = None

    def insert_after(self, count):
        t = self.next
        self.next = DoubleLinkNode(count)
        self.next.pre = self
        self.next.next = t
        t.pre = self.next

    def remove_key(self, key):
        self.keys.remove(key)
        if not self.keys:
            self.pre.next = self.next
            self.next.pre = self.pre

class AllOne(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = DoubleLinkNode()
        self.tail = DoubleLinkNode()
        self.head.next = self.tail
        self.tail.pre = self.head
        self.key2node = {}

    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        if key in self.key2node:
            node = self.key2node[key]
            if node.next.count != node.count+1:
                node.insert_after(node.count+1)
            node.next.keys.add(key)
            self.key2node[key] = node.next
            node.remove_key(key)
        else:
            if self.head.next.count != 1:
                self.head.insert_after(1)
            self.head.next.keys.add(key)
            self.key2node[key] = self.head.next

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        if key in self.key2node:
            node = self.key2node[key]
            if node.count > 1:
                if node.pre.count != node.count-1:
                    node.pre.insert_after(node.count-1)
                node.pre.keys.add(key)
                self.key2node[key] = node.pre
            else:
                self.key2node.pop(key)
            node.remove_key(key)

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        node = self.tail.pre
        if node != self.head:
            for key in node.keys:
                return key
        return ''

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        node = self.head.next
        if node != self.tail:
            for key in node.keys:
                return key
        return ''

# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()

# 14 / 14 test cases passed.
# Status: Accepted
# Runtime: 128 ms
# 36.31%
