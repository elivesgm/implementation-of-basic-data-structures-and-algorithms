
简单写出conhash的大致实现。待后续完善。

一致性hash大致原理：

1.根据权重复制生成vnode，每个vnode key不一样；
2.将vnode key计算hash分布到hash map中；

refers to 

[1] [Consistent-hashing](https://www.codeproject.com/Articles/56138/Consistent-hashing),codeproject.com.

[2] [consistent-hash](https://github.com/Charles0429/toys/blob/master/consistent-hash/consistent_hash.cpp#L63),github.com.
