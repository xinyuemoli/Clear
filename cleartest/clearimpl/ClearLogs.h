#pragma once
#include "../clear/Clear.h"
class ClearLogCache :public Clear
{
public:
    ClearLogCache();
    //类别展示名称
     std::wstring GetDisplayName() override;
    //类别描述
    std::wstring GetDescription() override;
    //
    void Scan(TCallBack callback) override;
    void Purge(std::vector<uint>& vec_clears) override;
private:
    std::vector<std::wstring> paths_;
};