#include "mem.h"

uintptr_t* FindDMAAddy(std::uintptr_t baseAddress, const std::vector<std::uintptr_t> offsets, const size_t size) {
	std::uintptr_t temp = *reinterpret_cast<std::uintptr_t*>(baseAddress + offsets[0]);
	std::uintptr_t* finalPtr = nullptr;

	for (int i = 1; i < size; i++) {
		if (i == size-1) {
			finalPtr = reinterpret_cast<std::uintptr_t*>(temp + offsets[i]);
		}
		else {
			temp = *reinterpret_cast<std::uintptr_t*>(temp + offsets[i]);
		}
	}

	return finalPtr;
}