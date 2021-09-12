class LockingTree:

    def __init__(self, parent: List[int]):
        self._node_map = {}
        for i in range(len(parent)):
            node = TreeNode()
            node.children = []
            self._node_map[i] = node
        # the order might be random, so we must init the tree after all nodes are created
        for i in range(len(parent)):
            node = self._node_map.get(i)
            parent_node = self._node_map.get(parent[i])
            if parent_node:
                node.parent = parent_node
                parent_node.children.append(node)

    def lock(self, num: int, user: int) -> bool:
        node = self._node_map.get(num)
        if not node:
            return False
        if node.locked_by_user:
            return False
        node.locked_by_user = user
        cur = node
        while cur.parent:
            cur.parent.locked_children_count += 1
            cur = cur.parent
        return True

    def unlock(self, num: int, user: int) -> bool:
        node = self._node_map.get(num)
        if not node :
            return False
        if not node.locked_by_user:
            return False
        if user != node.locked_by_user:
            return False
        node.locked_by_user = None
        cur = node
        while cur.parent:
            cur.parent.locked_children_count -= 1
            cur = cur.parent
        return True

    def upgrade(self, num: int, user: int) -> bool:
        node = self._node_map.get(num)
        if not node:
            return False
        if node.locked_by_user:
            return False
        if node.locked_children_count < 1:
            return False
        cur = node
        while cur.parent:
            if cur.parent.locked_by_user:
                return False
            cur = cur.parent
        self.lock(num, user)
        cur = node
        while cur.parent:
            cur.parent.locked_children_count -= node.locked_children_count
            cur = cur.parent
        self._unlock_sub_tree(node)
        node.locked_children_count = 0
        return True
    
    def _unlock_sub_tree(self, node):
        if not node:
            return
        for child in node.children:
            child.locked_by_user = None
            child.locked_chidlren_count = 0
            self._unlock_sub_tree(child)
        
class TreeNode:
    parent = None
    # it must be None, not [], otherwise it would be static
    children = None
    locked_by_user = None
    locked_children_count = 0

# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)
