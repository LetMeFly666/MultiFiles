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

void MultiFilesMerger::merge(vector<string>& toGenFiles, string toGenFileName = "merged.tffs", string infoFileName = "merged-info.json") {
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

