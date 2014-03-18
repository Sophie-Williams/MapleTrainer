#include <Windows.h>

/*
const DWORD *const pdwWallBase = reinterpret_cast<const DWORD *const>(0x013FCF98);
const DWORD dwLeftWallOffset = 0x0000001C;
const DWORD dwTopWallOffset = 0x00000020;
const DWORD dwRightWallOffset = 0x00000024;
const DWORD dwBottomWallOffset = 0x00000028;

int nGetLeftWall()
{
	__try
	{
		return *reinterpret_cast<DWORD *>(*pdwWallBase + dwLeftWallOffset);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return 0;
	}
}
int nGetRightWall()
{
	__try
	{
		return *reinterpret_cast<DWORD *>(*pdwWallBase + dwRightWallOffset);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return 0;
	}
}
int nGetTopWall()
{
	__try
	{
		return *reinterpret_cast<DWORD *>(*pdwWallBase + dwTopWallOffset);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return 0;
	}
}
int nGetBottomWall()
{
	__try
	{
		return *reinterpret_cast<DWORD *>(*pdwWallBase + dwBottomWallOffset);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return 0;
	}
}
*/

bool Teleport(_In_ int nX, _In_ int nY)
{
	__try
	{
		{

			DWORD dwUserLocal = *pdwUserLocal;
			setMapleData(dwUserLocal + dwTeleportToggleOffset, NULL, 0);
			setMapleData(dwUserLocal + dwTeleportXOffset, NULL, nX);
			setMapleData(dwUserLocal + dwTeleportYOffset, NULL, nY);
			setMapleData(dwUserLocal + dwTeleportToggleOffset, NULL, 1);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}
	return true;
}