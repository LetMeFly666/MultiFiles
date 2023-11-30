#include "../MultiFiles/pch.h"
#pragma comment(lib,"MultiFiles.lib")

int main() {
	MultiFilesMerger multiFilesMerger;
	//vector<string> toMerge = { "MultiFiles_ToMerge_SmallFiles/00000001.txt", "MultiFiles_ToMerge_SmallFiles/00000002.txt" };
	vector<string> toMerge;
	char thisFileName[256];
	for (int i = 1; i <= 1000000; i++) {
		sprintf_s(thisFileName, "MultiFiles_ToMerge_SmallFiles/%08d.txt", i);
		toMerge.push_back(thisFileName);
	}
	multiFilesMerger.merge(toMerge);
	return 0;
}