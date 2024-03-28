#include "entity.h"

entity::entity(std::uintptr_t objAddr) : addr(objAddr)
{
};

std::uintptr_t entity::getOffsetAddr(std::ptrdiff_t offset) {
	return (this->addr + offset);
}

Vector3 entity::getPos() {
	float x = *reinterpret_cast<float*>(this->getOffsetAddr(offsets::posX));
	float y = *reinterpret_cast<float*>(this->getOffsetAddr(offsets::posY));
	float z = *reinterpret_cast<float*>(this->getOffsetAddr(offsets::posZ));

	return Vector3(x, y, z);
}