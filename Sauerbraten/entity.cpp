#include "entity.h"

Entity::Entity(const std::uintptr_t objAddr) : addr(objAddr)
{
};

std::uintptr_t Entity::getOffsetAddr(const std::ptrdiff_t offset) {
	return (this->addr + offset);
}

std::uintptr_t Entity::getOffsetAddr(const std::vector<std::ptrdiff_t> offset) {
	return FindDMAAddy(this->addr, offset);
}

Vector3 Entity::getPos() {
	if (!this->checkValidity() or !this->isAlive()) {
		return Vector3(0, 0, 0);
	}

	float x = *reinterpret_cast<float*>(this->getOffsetAddr(offsets::posX));
	float y = *reinterpret_cast<float*>(this->getOffsetAddr(offsets::posY));
	float z = *reinterpret_cast<float*>(this->getOffsetAddr(offsets::posZ));

	return Vector3(x, y, z);
}

bool Entity::isAlive() {
	if (!this->checkValidity()) {
		return false;
	}

	std::uint64_t health = *reinterpret_cast<std::uintptr_t*>(this->addr + offsets::Health);

	if (!health) {
		return false;
	}
	return true;
}

bool Entity::checkValidity() {
	if (this->addr == NULL) {
		return false;
	}
}