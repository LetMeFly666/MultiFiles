#include "../MultiFiles/pch.h"
#pragma comment(lib,"MultiFiles.lib")

int main() {
	MultiFilesMerger multiFilesMerger;
	vector<string> toMerge = { "MultiFiles_ToMerge_SmallFiles/00000001.txt", "MultiFiles_ToMerge_SmallFiles/00000002.txt" };
	multiFilesMerger.merge(toMerge);
	return 0;
}