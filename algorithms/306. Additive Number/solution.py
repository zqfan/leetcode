class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        def str_add(s1, s2):
            res = []
            carry = 0; i1 = len(s1)-1; i2 = len(s2)-1
            while i1 >= 0 or i2 >=0:
                if i1 >= 0:
                    carry += ord(s1[i1]) - ord('0')
                if i2 >= 0:
                    carry += ord(s2[i2]) - ord('0')
                res.append(str(carry % 10))
                carry /= 10; i1 -= 1; i2 -= 1
            if carry:
                res.append('1')
            return ''.join(reversed(res))

        l = len(num)
        for i in xrange(l/2):
            if i > 0 and num[0] == '0':
                break
            s1 = num[:i+1]
            for j in xrange(i+1, 2*l/3):
                if j - i > 1 and num[i+1] == '0':
                    break
                s2 = num[i+1:j+1]
                s = str_add(s1, s2)
                k = j + 1
                while k < l:
                    if s != num[k:k+len(s)]:
                        break
                    k += len(s)
                    s, s2 = str_add(s2, s), s
                if k == l:
                    return True
        return False
