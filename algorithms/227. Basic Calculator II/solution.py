class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        queue = collections.deque()
        method = {
            "+": operator.add,
            "-": operator.sub,
            "*": operator.mul,
            "/": operator.div
        }
        pri = {
            operator.add: 0,
            operator.sub: 0,
            operator.mul: 1,
            operator.div: 1
        }
        i = 0; n = 0
        while i < len(s):
            if s[i].isdigit():
                n = n * 10 + int(s[i])
            elif s[i] in method:
                while queue and pri[method[s[i]]] <= pri[queue[-1]]:
                    op = queue.pop()
                    n1 = queue.pop()
                    n = op(n1, n)
                queue.append(n)
                queue.append(method[s[i]])
                n = 0
            i += 1
        queue.append(n)
        while len(queue) >= 3:
            n1 = queue.pop()
            op = queue.pop()
            n2 = queue.pop()
            queue.append(op(n2, n1))
        return queue.pop()
