#include "path.h"
#include <Windows.h>
namespace utils
{
    std::vector<PathPart> SplitPath(const std::wstring& path)
    {
        std::vector<PathPart> result;
        int start_find_offset = 0;  //从start_find_offset 开始查找
        int find_index = -1;
        bool is_looped = false;
        std::wstring tmp_path = path;
        while ((find_index = tmp_path.find(L'*', start_find_offset)) != -1)
        {
            is_looped = true;
            //以前面最近的'\'做分割
            int start_split_index = tmp_path.rfind(L'\\', find_index);
            int end_split_index = tmp_path.find(L'\\', find_index);
            int count = -1;
            if (end_split_index != -1)
            {
                count = end_split_index - start_split_index - 1;
            }
            std::wstring prefix_path = tmp_path.substr(start_find_offset, start_split_index + 1);
            PathPart part;
            if (!prefix_path.empty())
            {
                part.is_fix = true;
                part.path = prefix_path;
                result.push_back(part);
            }
            std::wstring path_part = tmp_path.substr(start_split_index + 1, count);
            if (!path_part.empty())
            {
                part.is_fix = false;
                part.path = path_part;
                result.push_back(part);
            }
            if (end_split_index == -1)
            {
                break;
            }
            //重置下次搜索
            /*start_find_offset = end_split_index + 1;*/
            tmp_path = tmp_path.substr(end_split_index + 1);
        }
        if (!is_looped)
        {
            PathPart part;
            part.is_fix = true;
            part.path = path;
            result.push_back(part);
        }

        return result;
    }
    std::wstring ExpandEnvironmentVariables(const std::wstring& path)
    {
        DWORD size = ExpandEnvironmentStrings(path.c_str(), nullptr, 0);
        std::vector<wchar_t> buffer(size);
        ExpandEnvironmentStrings(path.c_str(), buffer.data(), size);
        return std::wstring(buffer.data());
    }
}
