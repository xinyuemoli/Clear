#pragma once
#include "path.h"
namespace utils
{
    void GetFiles(std::wstring parent_path, std::wstring dst_patten, std::vector<utils::PathPart>& parts, int part_index);
   
    void FindFiles(std::wstring parent_path);
}