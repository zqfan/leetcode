#! /usr/bin/env python

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

# https://oj.leetcode.com/problems/linked-list-cycle-ii/
# Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
# Follow up:
# Can you solve it without using extra space?

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a list node\
    def detectCycle(self, head):
        """
        See: http://en.wikipedia.org/wiki/Floyd%27s_cycle-finding_algorithm#Tortoise_and_hare
        """
        tortoise = head
        hare = head
        while hare and hare.next:
            tortoise = tortoise.next
            hare = hare.next.next
            if tortoise == hare:
                break
        else:
            return

        tortoise = head
        while tortoise != hare:
            tortoise = tortoise.next
            hare = hare.next

        return tortoise
