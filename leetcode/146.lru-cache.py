#
# @lc app=leetcode id=146 lang=python3
#
# [146] LRU Cache
#
# https://leetcode.com/problems/lru-cache/description/
#
# algorithms
# Hard (24.96%)
# Likes:    3305
# Dislikes: 122
# Total Accepted:    327.2K
# Total Submissions: 1.2M
# Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
#
# Design and implement a data structure for Least Recently Used (LRU) cache. It
# should support the following operations: get and put.
#
# get(key) - Get the value (will always be positive) of the key if the key
# exists in the cache, otherwise return -1.
# put(key, value) - Set or insert the value if the key is not already present.
# When the cache reached its capacity, it should invalidate the least recently
# used item before inserting a new item.
#
# The cache is initialized with a positive capacity.
#
# Follow up:
# Could you do both operations in O(1) time complexity?
#
# Example:
#
#
# LRUCache cache = new LRUCache( 2 /* capacity */ );
#
# cache.put(1, 1);
# cache.put(2, 2);
# cache.get(1);       // returns 1
# cache.put(3, 3);    // evicts key 2
# cache.get(2);       // returns -1 (not found)
# cache.put(4, 4);    // evicts key 1
# cache.get(1);       // returns -1 (not found)
# cache.get(3);       // returns 3
# cache.get(4);       // returns 4
#
#
#
#
#


from collections import OrderedDict


class LRUCache:

    class Node:
        def __init__(self, key, val, left=None, right=None):
            self.key = key
            self.val = val
            self.left = left
            self.right = right

    def _remove(self, node):
        le = node.left
        le.right = node.right
        node.right.left = le

    def _insert_head(self, head, node):
        node.right = head.right
        node.left = head
        head.right.left = node
        head.right = node

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = LRUCache.Node(0, 0)
        self.tail = LRUCache.Node(0, 0, self.head)
        self.head.right = self.tail
        self.data = dict()

    def get(self, key: int) -> int:
        if key in self.data:
            node = self.data[key]
            self._remove(node)
            self._insert_head(self.head, node)
            return node.val
        return -1

    def put(self, key: int, value: int) -> None:
        # Your LRUCache object will be instantiated and called as such:
        # obj = LRUCache(capacity)
        # param_1 = obj.get(key)
        # obj.put(key,value)
        if key not in self.data and len(self.data) >= self.capacity:
            last_node = self.tail.left
            self._remove(last_node)
            self.data.pop(last_node.key)
        if key in self.data:
            node = self.data[key]
            node.val = value
            self._remove(node)
        else:
            node = LRUCache.Node(key, value)
        self.data[key] = node
        self._insert_head(self.head, node)


class LRUCacheSTL:

    def __init__(self, capacity: int):
        self.capacity = capacity
        # https://docs.python.org/3/library/collections.html#collections.OrderedDict
        self.data = OrderedDict()

    def get(self, key: int) -> int:
        if key in self.data:
            # move to head
            self.data.move_to_end(key, last=False)
            return self.data[key]
        return -1

    def put(self, key: int, value: int) -> None:
        # Your LRUCache object will be instantiated and called as such:
        # obj = LRUCache(capacity)
        # param_1 = obj.get(key)
        # obj.put(key,value)

        if key not in self.data and len(self.data) >= self.capacity:
            self.data.popitem()
        self.data[key] = value
        self.data.move_to_end(key, last=False)
