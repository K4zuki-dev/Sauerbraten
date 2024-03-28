#pragma once
#include <cstdint>
#include <vector>

namespace offsets {
	// Localplayer, all others are build on it
	const std::vector<std::ptrdiff_t> LocalPlayer = { 0x00312930, 0x0, 0x118, 0x0 };

	const std::ptrdiff_t Health = 0x340;
	const std::ptrdiff_t Armor = 0x348;

	// Offset from sauerbraten.exe
	const std::ptrdiff_t local_entityAmmount = 0x346C9C;

	// The entity list for bot match is offset from Localplayer, if u want to loop through entity list then go with +0x8 everytime (size of pointer x64)
	const std::ptrdiff_t local_entitylist = 0x470;

	const std::ptrdiff_t posX = 0x394;
	const std::ptrdiff_t posY = 0x398;
	const std::ptrdiff_t posZ = 0x39C;

	const std::vector<std::ptrdiff_t> yaw = { 0x346C90, 0x0, 0x3C };
	const std::vector<std::ptrdiff_t> pitch = { 0x346C90, 0x0, 0x40 };
}