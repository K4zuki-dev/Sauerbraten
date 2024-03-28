#include <Windows.h>
#include <thread>
#include <stdio.h>
#include <vector>
#include <cstdint>
#include "mem.h"
#include "vector.h"
#include "aimbot.h"
#include "offsets.h"
#include "entity.h"
#include "entitylist.h"

static void HackThread(HMODULE instance) {
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	printf("Cheat injected successfully!\n\n");

	std::uintptr_t process = reinterpret_cast<std::uintptr_t>(GetModuleHandleA("sauerbraten.exe"));
	std::uintptr_t localPlayerAddr = FindDMAAddy(process, offsets::LocalPlayer);

	std::uintptr_t* yawPtr = reinterpret_cast<std::uintptr_t*>(FindDMAAddy(process, offsets::yaw));
	std::uintptr_t* pitchPtr = reinterpret_cast<std::uintptr_t*>(FindDMAAddy(process, offsets::pitch));

	while (!GetAsyncKeyState(VK_END))
	{
		Sleep(1);
		if (!localPlayerAddr) {
			printf("Not starting that shi\n");
			localPlayerAddr = FindDMAAddy(process, offsets::LocalPlayer);
			continue;
		}

		std::uintptr_t enemyAddr = getEntityAddresses(1)[0];

		entity LocalPlayer(localPlayerAddr);
		entity Enemy(enemyAddr);

		// Change Health
		*reinterpret_cast<std::int64_t*>(LocalPlayer.getOffsetAddr(offsets::Health)) = 69420;
		*reinterpret_cast<std::int64_t*>(LocalPlayer.getOffsetAddr(offsets::Armor)) = 69420;

		Vector3 LocalPlayerPos = LocalPlayer.getPos();
		Vector3 EnemyPos = Enemy.getPos();

		overwriteAngles(yawPtr, pitchPtr, LocalPlayerPos, EnemyPos);
	}


	// IMPORTANT: dereference 1 will be offset by some value, cheat engine shows me:
	// CE:					0x193614730E0
	// Caluclated Value:	0x	 614730E0
	// Odly close, this is because in the memory region for the DLL the memory "starts" at the process so at sauerbraten.exe, which is 0
	// sauerbraten.exe's address = 0, and CE shows the absolte value in ur whole RAM
	// But because the DLL is only operating within the memory space of the programm for the DLL the memory starts at 0 which is at sauerbraten.exe

	if (f)
	{
		fclose(f);
	}

	FreeConsole();
	FreeLibraryAndExitThread(instance, 0);
}

// Entry:

extern "C" BOOL WINAPI DllMain(HMODULE const instance, DWORD const reason, LPVOID lpvReserved) {

	// DLL Process attach
	if (reason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(instance);


		const auto thread = CreateThread(
			nullptr,
			0,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(HackThread),
			instance,
			0,
			nullptr
		);

		if (thread) {
			CloseHandle(thread);
		}
	}

	return TRUE;
}