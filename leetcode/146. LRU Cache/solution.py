class Node(object):
    def __init__(self, val):
        self.val = val
        self.next = None
        self.pre = None

class List(object):
    def __init__(self):
        self.head = self.tail = Node(None)

    def pushleft(self, val):
        node = Node(val)
        self.move2head(node)
        return node

    def move2head(self, node):
        if self.head.next == node:
            return
        if node.pre:
            node.pre.next = node.next
        if node.next:
            node.next.pre = node.pre
        if self.head.next:
            self.head.next.pre = node
        node.next = self.head.next
        if self.tail == node:
            self.tail = node.pre
        if self.tail == self.head:
            self.tail = node
        node.pre = self.head
        self.head.next = node

    def pop(self):
        if self.head == self.tail:
            return
        val = self.tail.val
        pre = self.tail.pre
        self.tail.pre = None
        pre.next = None
        self.tail = pre
        return val

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.lru = List()
        # key: (value, node)
        self.kvn = {}

    def get(self, key):
        """
        :rtype: int
        """
        if key not in self.kvn:
            return -1
        self.lru.move2head(self.kvn[key][1])
        return self.kvn[key][0]

    def set(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        if key in self.kvn:
            self.lru.move2head(self.kvn[key][1])
            self.kvn[key][0] = value
        else:
            if len(self.kvn) >= self.capacity:
                self.kvn.pop(self.lru.pop())
            node = self.lru.pushleft(key)
            self.kvn[key] = [value, node]
