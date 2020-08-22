'''
https://leetcode-cn.com/problems/lru-cache/
146. LRU缓存机制
'''
class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.dic = collections.OrderedDict()

    def get(self, key: int) -> int:
        if key in self.dic:
            self.dic.move_to_end(key)#移动到最右
        return self.dic.get(key, -1)

    def put(self, key: int, value: int) -> None:
        if key in self.dic:
            del self.dic[key]#先删除再更改
        self.dic[key] = value
        if len(self.dic) > self.cap:#超出缓存大小弹出 最先进入的
            self.dic.popitem(last = False)#FIFO