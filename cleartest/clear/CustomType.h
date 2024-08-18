#pragma once
#include <Windows.h>
#include <string>
typedef unsigned int uint;
struct CacheItem
{
    uint id;
    uint size;
    std::wstring display_name;
};

typedef void (*TCallBack)(const CacheItem& cache_item);