class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        group = collections.defaultdict(list)
        for p in paths:
            p = p.split()
            for i in xrange(1, len(p)):
                filename, content = p[i].split('(')
                group[content[:-1]].append(p[0] + '/' + filename)
        return [p for c, p in group.iteritems() if len(p) > 1]
