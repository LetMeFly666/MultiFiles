#include "../MultiFiles/pch.h"
#pragma comment(lib,"MultiFiles.lib")

int main() {
	string mergedFileName = "../MultiFiles_MergerByCPP/merged.tffs";
	string infoFileName = "../MultiFiles_MergerByCPP/merged-info.txt";
	MultiFilesReader multiFilesReader(mergedFileName, infoFileName);
	string filename1 = "MultiFiles_ToMerge_SmallFiles/00000001.txt";
	string filename2 = "MultiFiles_ToMerge_SmallFiles/00000002.txt";
	string data1 = multiFilesReader.read(filename1);
	cout << filename1 << ": " << data1 << endl;
	string data2 = multiFilesReader.read(filename2);
	cout << filename2 << ": " << data2 << endl;
	return 0;
}