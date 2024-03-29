#include <cstdint>
#include "vector.h"
#include "offsets.h"
#include "mem.h"
#pragma once

class Entity {
public:
	const std::uintptr_t addr;

	Entity(const std::uintptr_t objAddr);

	std::uintptr_t getOffsetAddr(const std::ptrdiff_t offset);
	std::uintptr_t getOffsetAddr(const std::vector<std::ptrdiff_t> offset);

	Vector3 getPos();

	bool isAlive();

	template<typename T>
	void setOffsetValue(const std::ptrdiff_t offset, const T value) noexcept {
		void* ptrToOffset = reinterpret_cast<void*>(this->getOffsetAddr(offset));
		memcpy(ptrToOffset, &value, sizeof(T));
	}

	bool checkValidity();
};
