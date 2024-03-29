#include "entitylist.h"

std::uint16_t getPlayerAmmount() {
	std::uintptr_t process = reinterpret_cast<std::uintptr_t>(GetModuleHandleA("sauerbraten.exe"));
	return *reinterpret_cast<std::uintptr_t*>(process + offsets::local_entityAmmount);
}

std::uintptr_t getEntityListAddr() {
	std::uintptr_t process = reinterpret_cast<std::uintptr_t>(GetModuleHandleA("sauerbraten.exe"));
	std::uintptr_t localPlayerAddr = FindDMAAddy(process, offsets::LocalPlayer);
	return localPlayerAddr + offsets::local_entitylist;
}

std::vector<std::uintptr_t> getEntityAddresses(std::uint16_t ammount = getPlayerAmmount()) {
	std::uintptr_t entityListAddr = getEntityListAddr();
	std::vector<std::uintptr_t> entities = {};

	if (getPlayerAmmount() >= ammount) {
		for (int i = 0; i < ammount; i++) {
			std::uintptr_t entityAddrPtr = (*reinterpret_cast<std::uintptr_t*>(entityListAddr) + ((std::ptrdiff_t)(0x8 * i)));
			// if (entityAddr == localPlayerAddr) {continue;}
			entities.push_back(*reinterpret_cast<std::uintptr_t*>(entityAddrPtr));
		}
	}
	else 
	{
		for (int i = 0; i < getPlayerAmmount(); i++) {
			std::uintptr_t entityAddrPtr = (*reinterpret_cast<std::uintptr_t*>(entityListAddr) + ((std::ptrdiff_t)(0x8 * i)));
			entities.push_back(*reinterpret_cast<std::uintptr_t*>(entityAddrPtr));
		}
	}

	return entities;
}