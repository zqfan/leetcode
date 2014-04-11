# Copyright (C) 2014 ZhiQiang Fan <aji.zqfan@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

# Definition for singly-linked list with a random pointer.
# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if head is None: return
        # use a huge dict to store (old, new) node pairs
        pairs = {None: None, head: RandomListNode(head.label)}
        # copy linked list
        cur = head
        while cur.next:
            pairs[cur.next] = RandomListNode(cur.next.label)
            pairs[cur].next = pairs[cur.next]
            cur = cur.next
        # copy random pointer
        cur = head
        while cur:
            pairs[cur].random = pairs[cur.random]
            cur = cur.next
        return pairs[head]
