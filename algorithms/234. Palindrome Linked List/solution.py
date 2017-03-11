# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return True

        cur = head
        length = 1
        while cur.next:
            cur = cur.next
            length += 1

        middle = (length - 1)/ 2
        cur = head
        while middle > 0:
            cur = cur.next
            middle -= 1

        rev_head = self.reverse_link(cur.next)

        cur = head
        rev_cur = rev_head
        is_p = True
        while rev_cur:
            if rev_cur.val != cur.val:
                is_p = False
                break
            rev_cur = rev_cur.next
            cur = cur.next

        origin = self.reverse_link(rev_head)
        return is_p

    @staticmethod
    def reverse_link(head):
        cur = head
        pre = None
        while cur:
            t = cur.next
            cur.next = pre
            pre = cur
            cur = t
        return pre

# test
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def build_link(l):
    if not l:
        return None
    head = ListNode(l[0])
    pre = head
    for v in l[1:]:
        ln = ListNode(v)
        pre.next = ln
        pre = ln
    return head

def print_link(l):
    cur = l
    while cur:
        print cur.val,
        cur = cur.next
    print

s = Solution().isPalindrome
l = build_link([1,1,2,1])
assert False == s(l)
