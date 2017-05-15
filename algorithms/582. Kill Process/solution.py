class Solution(object):
    def killProcess(self, pid, ppid, kill):
        """
        :type pid: List[int]
        :type ppid: List[int]
        :type kill: int
        :rtype: List[int]
        """
        children = collections.defaultdict(list)
        for i in xrange(len(pid)):
            children[ppid[i]].append(pid[i])
        result = [kill]
        for p in result:
            result += children[p]
        return result

# 166 / 166 test cases passed.
# Status: Accepted
# Runtime: 329 ms
