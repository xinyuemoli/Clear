#pragma once
#include "../clear/Clear.h"
class ClearLogCache :public Clear
{
public:
    ClearLogCache();
    //���չʾ����
     std::wstring GetDisplayName() override;
    //�������
    std::wstring GetDescription() override;
    //
    void Scan(TCallBack callback) override;
    void Purge(std::vector<uint>& vec_clears) override;
private:
    std::vector<std::wstring> paths_;
};