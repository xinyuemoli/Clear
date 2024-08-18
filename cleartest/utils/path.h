#pragma once
#include <vector>
#include <string>
namespace utils
{
    struct PathPart
    {
        bool is_fix;
        std::wstring path;
    };
    std::vector<PathPart> SplitPath(const std::wstring& path);
    std::wstring ExpandEnvironmentVariables(const std::wstring& path);
}