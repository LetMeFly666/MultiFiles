<!--
 * @Author: LetMeFly
 * @Date: 2023-11-29 22:49:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-12-03 16:42:51
-->
# MultiFiles

机械磁盘上的大量小文件读/复制操作？太慢了怎么办？

**合并小文件：** 如果你在开发一款产品，这个产品中有大量的只读小文件（例如node项目），那么你可以调用MultiFiles库，将你认为的小文件全部打包到一起。这样，文件传输/解压安装的效率会大幅度提升。

**读取小文件：** 在需要读取文件时，调用MultiFiles库，避免了多次大量的IO操作。

## 使用方法

VisualStudio项目解决方案在```MultiFiles/MultiFiles.sln```。启动后将```MultiFiles_MergerByCPP```设置为启动项目，编译运行即可（第一次编译运行可能会失败，因为要先生成.dll和.lib文件，失败了就再编译一次就能成功了）。

**合并小文件：** 调用```MultiFiles.dll```的```MultiFilesMerger```类的```merge```方法。

参数：

+ vector<string>& toGenFiles：一个要合并的小文件的 文件名数组
+ string toGenFileName（可选）：合并后的文件名
+ string infoFileName（可选）：合并信息的文件名

返回：

+ None

**读取小文件：** 调用```MultiFiles.dll```的```MultiFilesReader```类的```read```方法。

类```MultiFilesReader```构造函数的参数：

+ string mergedFileName（可选）：合并后的文件名
+ string infoFileName（可选）：合并信息的文件名

方法```read```的参数：

+ string toReadFileName：要读取的文件的文件名

方法```read```的返回值：

+ string：该文件的内容（当无此文件时返回空字符串）

## TODO

后续计划：

- [ ] 自动选取小文件（当前必须手动选择一些小文件并把参数传递给MultiFiles，若MulitFiles能实现自动分析应用构成并自动选取小文件就更好了）
- [ ] 目录的支持（支持传递一个目录，若传递参数包括目录，则自动打包该目录下的所有文件）
- [ ] 多平台的支持（比如Linux？）
- [ ] 写文件的支持（当前仅支持只读小文件，暂不支持写文件）
- [ ] 文件读写失败的判断（读写文件可能失败）
- [ ] 统一文件读取接口的支持，或者说对C++自带读文件操作的兼容（使用MultiFiles.reader应该像使用ifstream一样才好）
- [ ] 当读取文件没有在“合并文件”中时，应当自动从磁盘中读取（这样就无需判断，全部使用MultiFiles来读 被合并的小文件 和 未被合并的大文件 了）
- [ ] 手动释放内存中的文件（当前是把小文件读到了内存中，若后续不需要这些数据可选择手动释放）
- [ ] 使用其他编程语言实现对该类的调用（当前使用Python调用失败了，是由于自己对动态链接库相关知识的不熟悉。也许Py调用DLL文件时不支持C++中的string类型而必须用原始C语言中的char *类型？）
- [ ] 压缩infoFiles（infoFiles中全是可显示ASCII字符，且由于小文件文件名的相似性(可能处于相同子目录)，该文件若压缩一下则可以进一步节省空间，但响应的会消耗一定的额外时间）
- [x] 不支持大于4G的文件，这是因为使用了32位有符号整数（emm，这已经不是小文件了好吧）

