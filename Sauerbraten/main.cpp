#include <Windows.h>
#include <thread>
#include <iostream>
#include "mem.h"

namespace offsets {
	const std::uintptr_t health[] = { 0x00312930, 0x0, 0x118, 0x340 };
}

static void HackThread(HMODULE instance) {
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	printf("Cheat injected successfully!\n\n");

	size_t sizeHealth = sizeof(offsets::health) / sizeof(offsets::health[0]);

	std::uintptr_t client = reinterpret_cast<uintptr_t>(GetModuleHandleA("sauerbraten.exe"));
	std::uintptr_t* healthAddr = FindFinalAdress(client, offsets::health, sizeHealth);

	while (!GetAsyncKeyState(VK_END))
	{
		Sleep(1);
		*healthAddr = 69420;
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