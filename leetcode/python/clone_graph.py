# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node: return
        old_nodes, new_nodes = [node], {}
        while len(old_nodes):
            old_node = old_nodes.pop(0)
            new_node = UndirectedGraphNode(old_node.label)
            new_node = new_nodes.setdefault(old_node.label, new_node)
            for neighbor in old_node.neighbors:
                if not new_nodes.get(neighbor.label):
                    old_nodes.append(neighbor)
                    new_neighbor = UndirectedGraphNode(neighbor.label)
                    new_nodes[neighbor.label] = new_neighbor
                    new_node.neighbors.append(new_neighbor)
                else:
                    new_node.neighbors.append(new_nodes.get(neighbor.label))
        return new_nodes.get(node.label)
