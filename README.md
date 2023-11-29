<!--
 * @Author: LetMeFly
 * @Date: 2023-11-29 22:49:31
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-11-29 23:36:34
-->
# MultiFiles

机械磁盘上的大量小文件读/复制操作？太慢了怎么办？

**合并小文件：** 如果你在开发一款产品，这个产品中有大量的只读小文件（例如node项目），那么你可以调用MultiFiles库，将你认为的小文件全部打包到一起。这样，文件传输/解压安装的效率会大幅度提升。

**读取小文件：** 在需要读取文件时，调用MultiFiles库，避免了多次大量的IO操作。

## 使用方法

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

+ string：该文件的内容

## TODO

后续计划：

+ [ ] 自动选取小文件（当前必须手动选择一些小文件并把参数传递给MultiFiles，若MulitFiles能实现自动分析应用构成并自动选取小文件就更好了）
+ [ ] 目录的支持（支持传递一个目录，若传递参数包括目录，则自动打包该目录下的所有文件）
+ [ ] 多平台的支持（比如Linux？）
+ [ ] 写文件的支持（当前仅支持只读小文件，暂不支持写文件）

## More

距离高级操作系统作业的提交截止时间（2023.11.30 20:30）还有不足24h。

> <del>做完PPT整财务，整完财务写标书，标书还没写完又有结项报告要写...  ——当代某研一学生的emo</del>