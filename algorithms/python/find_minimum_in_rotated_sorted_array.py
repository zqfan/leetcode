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

# https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        if not num: return
        left, mid, right = 0, 0, len(num) - 1
        while left <= right:
            # it is sorted, such case means no rotated at all
            if num[left] <= num[right]:
                return num[left]
            mid = (left + right) / 2
            # such case means left is ordered, so rotated part is on the right.
            if num[mid] > num[left]:
                left = mid
            elif num[mid] < num[left]:
                right = mid
            # no duplicated element, so equal means only two elements left,
            # and num[left] is not less than num[right]
            else:
                return num[right]
        return num[mid]
