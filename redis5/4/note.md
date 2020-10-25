

## 摘要
```
# include <endian.h> 中定义了 #define __BYTE_ORDER __LITTLE_ENDIAN 可以判断大小端
```

## 问题
- [ ] 放入ziplist，要求list 或 zset 单个元素的大小么，要求list 的元素必须是字符串么，zset如何保证有序，还是copy一份，在内存里排序
- [ ] 