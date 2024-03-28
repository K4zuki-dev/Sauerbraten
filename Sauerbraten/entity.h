#include <cstdint>
#include "vector.h"
#include "offsets.h"
#pragma once

class entity {
public:
	std::uintptr_t addr;

	entity(std::uintptr_t objAddr);

	std::uintptr_t getOffsetAddr(std::ptrdiff_t offset);

	Vector3 getPos();
};
