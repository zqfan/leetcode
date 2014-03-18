#! /usr/bin/env python

import __builtin__
import os
import sys

class UndirectedGraphNode(object):
    def __init__(self, x):
        self.label = x
        self.neighbors = []

__builtin__.UndirectedGraphNode = UndirectedGraphNode

def _get_python_dir():
    tests_dir = os.path.dirname(os.path.realpath(__file__))
    pardir = os.path.join(tests_dir, os.path.pardir)
    return os.path.abspath(os.path.join(pardir, 'python'))

sys.path.append(_get_python_dir())

import clone_graph

def serialize_graph(node):
    ret = ''
    unhandled = [node]
    visited = set()
    while len(unhandled):
        cur = unhandled.pop(0)
        if cur.label in visited:
            continue
        visited.add(cur.label)
        ret += str(cur.label)
        for n in cur.neighbors:
            ret += ',' + str(n.label)
            if n.label not in visited:
                unhandled.append(n)
        ret += '#'
    return ret[:-1]

def deserialize_graph(string):
    nodes = string.split('#')
    cache = {}
    for node in nodes:
        lables = node.split(',')
        cache[lables[0]] = lables[1:]
    first = UndirectedGraphNode(string.split(',')[0])
    visited = set()
    unhandled = [first]
    while len(unhandled):
        curnode = unhandled.pop(0)
        visited.add(curnode.label)
        neighbors = cache.get(curnode.label)
        for neighbor in neighbors:
            if neighbor == curnode.label:
                curnode.neighbors.append(curnode)
            if neighbor in visited:
                continue
            neighbor_node = UndirectedGraphNode(neighbor)
            curnode.neighbors.append(neighbor_node)
            unhandled.append(neighbor_node)
    return first

def run_test():
    dirname = os.path.dirname(__file__)
    func = clone_graph.Solution().cloneGraph
    with open(os.path.join(dirname, 'clone_graph.test')) as f:
        lines = f.readlines()
        for line in lines:
            line = line.strip()[1:-1]
            graph_first_node = deserialize_graph(line)
            assert line == serialize_graph(graph_first_node)
            cloned_node = func(graph_first_node)
            string = serialize_graph(cloned_node)
            assert line == string, '%s != %s' % (line, string)
            print 'success: %s' % line

if __name__ == '__main__':
    run_test()
