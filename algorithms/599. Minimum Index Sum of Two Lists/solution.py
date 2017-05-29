class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        common = set(list1) & set(list2)
        counter = collections.defaultdict(int)
        for i, s in enumerate(list1):
            counter[s] += i
        for i, s in enumerate(list2):
            counter[s] += i
        m = min(counter[s] for s in common)
        return [s for s in common if counter[s] == m]
