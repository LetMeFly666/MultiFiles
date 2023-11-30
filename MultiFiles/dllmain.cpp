// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

void MultiFilesMerger::merge(vector<string>& toGenFiles, string toGenFileName, string infoFileName) {
    int totalBytes = 0;
    ofstream ostrTFFS(toGenFileName, ios::out | ios::binary);
    ofstream ostrInfo(infoFileName, ios::out);
    for (string& thisFile : toGenFiles) {
        ifstream istr(thisFile, ios::in | ios::binary);
        string data;
        istr >> data;
        ostrTFFS << data;
        ostrInfo << thisFile << '|' << totalBytes << '|' << data.size() << endl;  // 文件名|开始位置|文件长度\n
        totalBytes += data.size();
        istr.close();
    }
    ostrTFFS.close();
    ostrInfo.close();
}

MultiFilesReader::MultiFilesReader(string mergedFileName, string infoFileName) : mergedFileName(mergedFileName), infoFileName(infoFileName) {
    ifstream istrTFFS(mergedFileName, ios::in | ios::binary);
    ifstream istrInfo(infoFileName, ios::in);
    string thisLine;
    while (getline(istrInfo, thisLine)) {
        if (thisLine.size() < 3) {
            continue;
        }
        int firstSplitLoc = thisLine.find_first_of('|');
        int lastSplitLoc = thisLine.find_last_of('|');
        string thisFileName = thisLine.substr(0, firstSplitLoc);
        string beginLocString = thisLine.substr(firstSplitLoc + 1, lastSplitLoc - firstSplitLoc - 1);
        int beginLoc = atoll(beginLocString.c_str());  // 忽然发现这个似乎不需要，顺序读就行了
        string lengthString = thisLine.substr(lastSplitLoc + 1, thisLine.size() - lastSplitLoc - 1);
        int length = atoll(lengthString.c_str());
        char *dataChar = new char[length + 1];
        istrTFFS.read(dataChar, length);
        string data(dataChar);
        delete[] dataChar;
        file2data[thisFileName] = data;
    }
}

string MultiFilesReader::read(string toReadFileName) {
    return file2data[toReadFileName];
}
