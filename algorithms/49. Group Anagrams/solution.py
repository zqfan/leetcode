class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        category = collections.defaultdict(list)
        for s in strs:
            category[''.join(sorted(s))].append(s)
        return category.values()
