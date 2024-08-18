// cleartest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "clearimpl/ClearLogs.h"
#include <shlwapi.h>
#pragma comment(lib,"shlwapi.lib")

#include <D:\codes\tool-codes\utils\strutils.h>

bool IsDirectory(std::wstring& path)
{
    if (path.empty())
    {
        return false;
    }
    return GetFileAttributes(path.c_str()) & FILE_ATTRIBUTE_DIRECTORY;
}

void FindFiles(std::wstring path)
{
    //
    std::vector<std::wstring>path_parts = StrSplit(path.c_str(), L"\\");
    int level = 0, max_level = path_parts.size();
    std::wstring combinations_path, last_path;
    while (level < max_level)
    {
        combinations_path += path_parts[level];
        if (PathFileExists(combinations_path.c_str()))
        {
            //前进
            level++;
            last_path = combinations_path;
        }
        else if (!IsDirectory(last_path))
        {
            return;
        }
        else
        {
            //展开展开文件夹

        }
    }
}

void PathExpansion(S)
{
    //1 将目标路径分开[C:\,windows,1,2]
    //
    std::vector<std::wstring> s;
    int size = s.size();
    int level = 0;
    std::wstring path;
    std::wstring last_path;
    while (level < size)
    {
        path += s[level];
        if (PathFileExist(path))
        {
            level++;
            last_path = path;
        }
        else if (!IsDirectory(last_path))
        {
            break;
        }
        else
        {
            //展开
            Find(last_path, level, max_level, dst_patten)
            {
                tmp = last_path + L"\\*";
                FindFirstFile(last_path);
                IsDirectory(new_path) && level < max_level;
                //截取同样长度的路径看卡是否满足
            }
        }
    }
}

int main()
{
    /*ClearLogCache logCache;
    logCache.Scan(NULL);*/

    std::wstring str = utils::ExpandEnvironmentVariables(L"%windir%\\Soft*Distribution*");
    WIN32_FIND_DATA data = {};
    HANDLE hFind = FindFirstFile(str.c_str(), &data);
    if (hFind == INVALID_HANDLE_VALUE)
    {
        std::cout << 111 << std::endl;
    }
    bool b = PathMatchSpecA("C:\\Windows\\Logs\\MoSetup", "C:\\Windows\\Logs\\*\\*.log");
    DWORD dd = GetLastError();
    int a = 0;
}