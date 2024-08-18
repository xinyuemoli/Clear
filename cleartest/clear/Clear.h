#pragma once
#include "CustomType.h"
#include <vector>
class Clear
{
public:
    //类别展示名称
    virtual std::wstring GetDisplayName() = 0;
    //类别描述
    virtual std::wstring GetDescription() = 0;
    //
    virtual void Scan(TCallBack callback) = 0;
    virtual void Purge(std::vector<uint>& vec_clears) = 0;
};