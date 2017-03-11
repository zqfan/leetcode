class DoubleLinkNode(object):
    def __init__(self, val=None):
        self.val = val
        self.pre = None
        self.next = None

    def insert_after(self, node):
        self.next = node.next
        self.pre = node
        if self.next:
            self.next.pre = self
        node.next = self

    def delete(self):
        self.pre.next = self.next
        self.next.pre = self.pre

class FrequencyNode(DoubleLinkNode):
    def __init__(self, val=0):
        self.val = val
        self.pre = None
        self.next = None
        self.timehead = DoubleLinkNode()
        self.timetail = DoubleLinkNode()
        self.timetail.insert_after(self.timehead)

    def delete_timenode(self, timenode):
        timenode.delete()
        if self.val != 0 and self.timehead.next == self.timetail:
            self.delete()

class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.keys = {}
        self.freqlink = FrequencyNode()
        FrequencyNode().insert_after(self.freqlink)

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.keys:
            return -1
        freqnode = self.keys[key]['freqnode']
        t = freqnode.next
        if freqnode.val + 1 != t.val:
            t = FrequencyNode(freqnode.val + 1)
            t.insert_after(freqnode)
        timenode = self.keys[key]['timenode']
        freqnode.delete_timenode(timenode)
        timenode.insert_after(t.timehead)
        self.keys[key]['freqnode'] = t
        return self.keys[key]['value']

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if self.capacity <= 0:
            return
        if key not in self.keys:
            timenode = DoubleLinkNode(key)
            timenode.insert_after(self.freqlink.timehead)
            self.keys[key] = {}
            self.keys[key]['freqnode'] = self.freqlink
            self.keys[key]['timenode'] = timenode
            if len(self.keys) > self.capacity:
                freqnode = self.freqlink.next
                self.keys.pop(freqnode.timetail.pre.val)
                freqnode.delete_timenode(freqnode.timetail.pre)
        self.keys[key]['value'] = value
        self.get(key)

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
