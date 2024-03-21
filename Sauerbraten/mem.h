#pragma once
#include <vector>

uintptr_t* FindDMAAddy(std::uintptr_t baseAddress, const std::vector<std::uintptr_t> offsets, const size_t size);
