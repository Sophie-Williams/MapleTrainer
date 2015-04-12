#include <windows.h>

DWORD GetValue(DWORD dwBase, DWORD dwOffset)
{
	__try
	{
		return *(PDWORD)(dwBase + dwOffset);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return 0;
	}
}

ULONG_PTR ReadPointer(ULONG_PTR* ulBase, INT nOffset){
	if (!IsBadReadPtr((VOID*)ulBase, sizeof(ULONG_PTR))){
		if (!IsBadReadPtr((VOID*)((*(ULONG_PTR*)ulBase)+nOffset), sizeof(ULONG_PTR))){
			return *(ULONG_PTR*)((*(ULONG_PTR*)ulBase)+nOffset);
		}
	}
	return 0;
}

// reading nested pointers
ULONG_PTR readMultiPointer(ULONG_PTR ulBase, int level, ...)
{
	ULONG_PTR ulResult = -1;
	int i, offset;

	va_list	vaarg;
	va_start(vaarg, level);

	if (!IsBadReadPtr((void*)ulBase, sizeof(ULONG_PTR)))
	{
		ulBase = *(ULONG_PTR*)ulBase; //dereference the address of the pointer
		for (i = 0; i < level; i++)
		{
			offset = va_arg(vaarg, int);
			if (IsBadReadPtr((void*)(ulBase + offset), sizeof(ULONG_PTR)))
			{
				va_end(vaarg);
				return -1;
			}
			ulBase = *(ULONG_PTR*)(ulBase + offset);
		}
		ulResult = ulBase;
	}

	va_end(vaarg);
	return ulResult;
}


bool WritePointer(DWORD pointer, DWORD offset, int value){
	__try { 
		*(DWORD*)(*(DWORD*) pointer + offset) = value; 
		return true; 
	}
	__except (EXCEPTION_EXECUTE_HANDLER) { 
		return false; 
	}
}

