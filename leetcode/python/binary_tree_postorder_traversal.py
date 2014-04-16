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

# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        """
        I don't want to store the parent code and read it val after
        traver left and right. So I read parent node first, then
        traver right and then left. Finally, I reverse the order of
        record to get what we want.
        """
        if not root: return []
        ret, unvisit = [], [root]
        while unvisit:
            node = unvisit.pop()
            ret.append(node.val)
            if node.left:
                unvisit.append(node.left)
            if node.right:
                unvisit.append(node.right)
        return ret[::-1]
