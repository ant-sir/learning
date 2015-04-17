'''
Created on 2015年4月14日

@author: zyl
'''
"""
Python 基础部分

python中有四个主要类型（以及操作）的分类：
    数字（整数，浮点数，二进制数，分数）
    序列（字符串，列表，元组）
    映射（字典）
    集合（是自成一体的一个分类）
python类型的可变性分类：
    不可变类型（数字，字符串，元组，不可变集合）
    可变类型（列表，字典，可变集合）
对象灵活性：
    列表，字典和元组可以包含任何种类的对象。
    列表，字典和元组可以任意嵌套。
    列表和字典可以动态地扩大和缩小。
The full iteration protocot:
(It’s really based on two objects, used in two distinct steps by iteration tools)
    1. The iterable object you request iteration for, whose __iter__ is run by iter.
    2. The iterator object returned by the iterable that actually produces values during the iteration, whose __next__ is run by next and raises StopIteration when finished producing results.
In some cases these two objects are the same when only a single scan is supported (e.g., files).and the iterator object is often temporary, used internally by the iteration tool.
Moreover, some objects are both an iteration context tool (they iterate) and an iterable object (their results are iterable)—including generator expressions, map, zip, range and some dictionary methods.
A file object is its own iterator. Because they support just one iteration (they can’t seek backward to support multiple active scans), files have their own __next__ method and do not need to return a different object.

range支持在其结果上的多个迭代器，zip, map和filter不支持结果上的多个迭代器。

列表解析：
    当我们开始考虑在一个序列中的每项上执行一个操作时，都可以考虑使用列表解析。
扩展的列表解析：
    
"""


if __name__ == '__main__':
    pass