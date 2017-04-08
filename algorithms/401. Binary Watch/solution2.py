class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        self.solutions = []
        choices = [480, 240, 120, 60, 32, 16, 8, 4, 2, 1]
        self.find_solutions(num, 0, choices, 0)
        return self.convert_solutions()

    def find_solutions(self, num, minutes, choices, i):
        if num == 0:
            # 32+16+8+4 == 60, drop such solution
            if sum(choices[4:8]) == 0:
                return
            self.solutions.append(minutes)
            return
        if i >= len(choices):
            return
        self.find_solutions(num, minutes, choices[:], i + 1)
        minute = choices[i]
        choices[i] = 0
        self.find_solutions(num - 1, minutes + minute, choices, i + 1)

    def convert_solutions(self):
        strtimes = []
        for s in self.solutions:
            if s >= 720:
                continue
            hours = s / 60
            minutes = s % 60
            strtimes.append("%d:%02d" % (hours, minutes))
        return strtimes

# test
s = Solution()
ss = []
for i in range(0, 11):
    ss.append(set(s.readBinaryWatch(i)))
import itertools
for x in itertools.combinations(ss, 2):
    assert not (x[0] & x[1])
