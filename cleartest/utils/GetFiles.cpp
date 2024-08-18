#include "GetFiles.h"
#include <Windows.h>
#include <regex>
#include <iostream>
namespace utils
{
    void GetFiles(std::wstring parent_path, std::wstring dst_patten, std::vector<utils::PathPart>& parts, int part_index)
    {
        WIN32_FIND_DATA find_data;

        std::wstring tmp_parent_path = parent_path;
        if (parent_path.find_last_of(L"\\") == parent_path.length() - 1)
        {
            parent_path.append(L"*");
        }
        else
        {
            parent_path.append(L"\\*");
        }

        HANDLE find_handle = FindFirstFile(parent_path.c_str(), &find_data);
        if (find_handle == INVALID_HANDLE_VALUE)
        {
            return;
        }
        bool go_on = true;
        while (go_on)
        {
            if (tmp_parent_path[tmp_parent_path.length() - 1] != L'\\')
            {
                tmp_parent_path.append(L"\\");
            }

            bool is_directory = ((find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
            if (is_directory && (wcscmp(find_data.cFileName, L".") == 0 || wcscmp(find_data.cFileName, L"..") == 0))
            {
                //不处理
            }
            else
            {
                std::wregex regex(dst_patten);
                if (std::regex_search(find_data.cFileName, regex))
                {
                    //是需要的文件或目录
                    if (is_directory)
                    {
                        std::wstring new_parent_path = tmp_parent_path + find_data.cFileName;
                        int new_part_index = part_index + 1;
                        std::wstring new_dst_patten;
                        if (parts.size() - 1 < new_part_index)
                        {
                            new_dst_patten = L".*";
                        }
                        else
                        {
                            new_dst_patten = parts[new_part_index].path;
                        }

                        GetFiles(new_parent_path, new_dst_patten, parts, new_part_index);
                    }
                    else
                    {
                        //文件
                        std::wstring file_path = tmp_parent_path + find_data.cFileName;
                        std::wcout << file_path.c_str() << std::endl;
                    }
                }
            }

            //枚举下一个文件
            go_on = FindNextFile(find_handle, &find_data);
        }
    }
    void FindFiles(std::wstring parent_path)
    {
        //1 根据\\ 分割路径
        //2 PathFileExist(1),存在的话，就连接后面一部分的路径。
        //不存在的话，就枚举前一个路径下的所有文件，然后用PathMatchSpecA匹配
        WIN32_FIND_DATA find_data;
        HANDLE find_handle = FindFirstFile(parent_path.c_str(), &find_data);
        if (find_handle == INVALID_HANDLE_VALUE)
        {
            return;
        }
        do
        {
            bool is_directory = find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;

            if (is_directory && (wcscmp(find_data.cFileName, L".") == 0 || wcscmp(find_data.cFileName, L"..") == 0))
            {
                continue;
            }

            std::wstring tmp_parent_path = parent_path;
            std::wstring file_path;
            int find_pos = parent_path.rfind(L"\\*");
            int pos = parent_path.length() - wcslen(L"\\*");
            if (find_pos == pos)
            {
                tmp_parent_path = parent_path.substr(0, parent_path.length() - wcslen(L"\\*"));
                tmp_parent_path += L"\\";
                file_path = tmp_parent_path + find_data.cFileName;
            }
            else
            {
                find_pos = parent_path.rfind(L"\\");
                if (find_pos != -1)
                {
                    file_path = parent_path.substr(0, find_pos + 1) + find_data.cFileName;
                }
            }
            if (is_directory)
            {
                std::wstring new_path = tmp_parent_path + find_data.cFileName + L"\\*";
                FindFiles(new_path);
            }
            else
            {
                std::wcout << file_path.c_str() << std::endl;
            }
        } while (FindNextFile(find_handle, &find_data));
    }
}