# Copyright (C) 2015 ZhiQiang Fan <aji.zqfan@gmail.com>
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

# Given an array of integers and an integer k,
# find out whether there there are two distinct indices
# i and j in the array such that nums[i] = nums[j]
# and the difference between i and j is at most k.

class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        if k <= 0: return False
        hashmap = {}
        for index, num in enumerate(nums):
            if num in hashmap:
                if index - hashmap[num] <= k:
                    return True
            hashmap[num] = index
        return False
