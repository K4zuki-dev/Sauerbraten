#pragma once
#include <vector>

// Gives you back the final address of the thing you are looking for, cast it to a pointer and dereference it to actually get the value the address holds
uintptr_t FindDMAAddy(std::uintptr_t baseAddress, std::vector<std::ptrdiff_t> offsets);
