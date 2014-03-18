#include <windows.h>

extern void update();
extern int Main();

void WINAPI MainThread(){
	AllocConsole();
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)update, NULL, 0, NULL); //create thread to update values
	Main(); //located in MyForm.cpp, This will load the form and display it
}

//Entry Point. Executed when DLL is injected.
BOOL WINAPI DllMain ( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved ){
	switch ( fdwReason ) {
	case DLL_PROCESS_ATTACH:

		DisableThreadLibraryCalls(hinstDLL);

		if ( CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL) == NULL ) {
			return FALSE;
		}
		break;

	case DLL_PROCESS_DETACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}