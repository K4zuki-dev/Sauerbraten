#pragma once
#include <vector>
#include "mem.h"
#include "offsets.h"
#include "Windows.h"

std::uint16_t getPlayerAmmount();
std::uintptr_t getEntityListAddr();
std::vector<std::uintptr_t> getEntityAddresses(std::uint16_t ammount);

