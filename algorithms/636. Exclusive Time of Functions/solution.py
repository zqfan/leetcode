class Solution(object):
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        result, stack, last_time = [0] * n, [], 0
        for log in logs:
            fn, typestr, time = log.split(':')
            fn, time = int(fn), int(time)
            if typestr == "start":
                if stack:
                    result[stack[-1]] += time - last_time
                stack.append(fn)
                last_time = time
            else:
                result[stack.pop()] += time - last_time + 1
                last_time = time + 1
        return result

# 120 / 120 test cases passed.
# Status: Accepted
# Runtime: 95 ms
