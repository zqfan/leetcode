class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        num_str_arr = [""] * n
        for i in range(1, n+1):
            num_str = ""
            if i % 3 != 0 and i % 5 != 0:
                num_str = str(i)
            else:
                if i % 3 == 0:
                    num_str = "Fizz"
                if i % 5 == 0:
                    num_str += "Buzz"
            num_str_arr[i-1] = num_str
        return num_str_arr
