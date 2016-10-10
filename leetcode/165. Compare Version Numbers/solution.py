class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        ver_seq_1 = version1.split('.')
        ver_seq_2 = version2.split('.')
        for i in range(min(len(ver_seq_1), len(ver_seq_2))):
            v1 = int(ver_seq_1[i])
            v2 = int(ver_seq_2[i])
            if v1 != v2:
                return 1 if v1 > v2 else -1
        ver_sum_1 = sum(map(lambda x: int(x), ver_seq_1))
        ver_sum_2 = sum(map(lambda x: int(x), ver_seq_2))
        if ver_sum_1 == ver_sum_2:
            return 0
        else:
            return 1 if ver_sum_1 > ver_sum_2 else -1
