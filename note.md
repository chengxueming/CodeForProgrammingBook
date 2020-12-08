https://blog.csdn.net/zong596568821xp/article/details/81134406


## 2020年12月15日
> 使用 GNU Libtool 可以容易的在不同的系统中建立动态链接库。它通过一个称为 Libtool 库的抽象，隐藏了不同系统之间的差异，给开发人员提供了一致的的接口。
- [使用 GNU Libtool 创建库](https://www.ibm.com/developerworks/cn/aix/library/1007_wuxh_libtool/index.html)
创建依赖文件
```
[cxm@study libtool]$ libtool --mode=compile gcc -c compress.c // 先建立 Libtool 对象文件
[cxm@study libtool]$ libtool --mode=link gcc -o libcompress.la compress.lo -rpath /tmp -lz // 注意这里使用 compress.lo 作为输入文件，并且告诉 Libtool 生成的目标文件为 libcompress.la
[cxm@study libtool]$ libtool --mode=install install -c libcompress.la /tmp // 可以看到它安装了真实的动态链接库和静态链接库，同时也安装了 Libtool 库文件 libcompress.la，这个文件可以被后续的 Libtool 命令使用。
[cxm@study libtool]$ libtool -n --mode=finish /tmp //如果不能正常的使用安装好的库，请运行这个命令。
```
使用依赖文件
```
[cxm@study libtool]$ libtool --mode=compile gcc -c main.c // 我们还是要先为 main.c 建立 Libtool 对象文件，这和前面的方法一样 :
[cxm@study libtool]$ libtool --mode=link gcc -o main main.lo /tmp/libcompress.la // 我们也可以直接使用 libcompress.a 或者 libcompress.so，但是使用 Libtool 更加简单，因为它会将帮助你解决依赖关系，例如我们的 libcompress 依赖 libz。
```