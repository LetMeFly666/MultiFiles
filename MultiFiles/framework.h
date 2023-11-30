#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

extern "C" __declspec(dllexport) class MultiFilesMerger {
public:
	/* 将toGenFiles中的所有文件压缩合并到toGenFileName中 */
	void __declspec(dllexport) merge(vector<string>& toGenFiles, string toGenFileName = "merged.tffs", string infoFileName = "merged-info.json");
};

extern "C" __declspec(dllexport) class MultiFilesReader {
private:
	string mergedFileName;
	string infoFileName;
	unordered_map<string, string> file2data;
public:
	__declspec(dllexport) MultiFilesReader(string mergedFileName = "merged.ttfs", string infoFileName = "merged-info.json");
	/* 读取一个小文件 */
	string __declspec(dllexport) read(string toReadFileName);
};