#include <Windows.h>

DWORD GetValue(DWORD dwBase, DWORD dwOffset);
__inline ULONG_PTR ReadPointer(ULONG_PTR* ulBase, INT nOffset);
bool WritePointer(DWORD pointer, DWORD offset, int value);
ULONG_PTR readMultiPointer(ULONG_PTR ulBase, int level, ...);