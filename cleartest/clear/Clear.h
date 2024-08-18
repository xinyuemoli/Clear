#pragma once
#include "CustomType.h"
#include <vector>
class Clear
{
public:
    //���չʾ����
    virtual std::wstring GetDisplayName() = 0;
    //�������
    virtual std::wstring GetDescription() = 0;
    //
    virtual void Scan(TCallBack callback) = 0;
    virtual void Purge(std::vector<uint>& vec_clears) = 0;
};