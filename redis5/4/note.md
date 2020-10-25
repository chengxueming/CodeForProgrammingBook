
```c
unsigned char *ziplistNew(void); // 创建压缩列表
unsigned char *ziplistInsert(unsigned char *zl, unsigned char *p, unsigned char *s, unsigned int slen); // 插入元素
```
## 摘要
```
# include <endian.h> 中定义了 #define __BYTE_ORDER __LITTLE_ENDIAN 可以判断大小端
```

## 问题
- [ ] 放入ziplist，要求list 或 zset 单个元素的大小么，要求list 的元素必须是字符串么，zset如何保证有序，还是copy一份，在内存里排序


## 参考
[查看 gcc/g++ 预编译结果
](https://blog.csdn.net/yasi_xi/article/details/9744815)