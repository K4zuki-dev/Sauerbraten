#include "mem.h"

uintptr_t FindDMAAddy(std::uintptr_t baseAddress, std::vector<std::ptrdiff_t> offsets) {
	std::uintptr_t ptr = *reinterpret_cast<std::uintptr_t*>(baseAddress + offsets[0]);

	for (int i = 1; i < offsets.size(); i++) {
		if (ptr != NULL) {
			if (i == offsets.size() - 1) {
				ptr = static_cast<std::uintptr_t>(ptr + offsets[i]);
				break;
			}
			ptr = *reinterpret_cast<std::uintptr_t*>(ptr + offsets[i]);
		}
		else {
			return NULL;
		}
	}

	return ptr;
}