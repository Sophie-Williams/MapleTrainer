#include <windows.h>
#include <iostream>
#include <ctime>
#include "PointerUtil.h"

#pragma region Addresses

const DWORD ADDRESS_SetMapleStoryData = 0x00518430;   // 56 8B ? 8B ? ? ? ? ? 41 [3rd Result]

const DWORD ItemHookCMP = 0x005DE01C;                 // 85 C0 75 4E 8D 4C ? ? C7 44 24 44 ? ? ? ? E8
const DWORD ADDRESS_PtInRect = 0x016B5D2C;            // In Cheat Engine -> Memory Viewer, go to address "PtInRect" and then 4 byte scan it

const DWORD Stats_Base = 0x016A5C58;                     // 8B 0D ? ? ? ? 52 6A ? 56 E8 ? ? ? ? 8B BF
const DWORD HPOff = 0x0000251C;                       // 89 8E ? ? 00 00 80 BE ? ? 00 00 00 75 52 8B
const DWORD MPOff = HPOff + 4;
const DWORD ExpOff = 0x00002130;                      // maybe

const DWORD AlertBase = 0x016A5B7C;                   // 8B 15 ? ? ? ? 8B 4A ? 8D 0C 89 85 C9 74 27 8B
const DWORD HPAlertOff = 0x00000050;                  // 8B 48 ? 8d 0C 89 85 C9 74 27 8B
const DWORD MPAlertOff = HPAlertOff + 4;

const DWORD CharBase = 0x016A1234;                    // 8B 3D ? ? ? ? 8B 40
//alternate CharBase AoB:								 8B ? ? ? ? ? 85 C9 74 ? 83 B8 ? ? ? ? 00 74 ? 8B ? ? ? ? ? 85 C0 7E ? 8B
const DWORD CharPID = 0x0000353C;                     // 8B 86 ? ? 00 00 6A D8
const DWORD CharXOff = 0x00009E2C;                    // 89 8E ? ? ? ? 8B 50 ? 8B 06 89 96 ? ? ? ? 8B 50
const DWORD CharYOff = CharXOff + 4;
const DWORD AtkCountOff = 0x00008CF8;                 // 89 ? ? ? 00 00 C7 ? ? ? 00 00 ? 00 00 00 89 ? ? ? 00 00 89 ? ? ? 00 00 89 ? ? ? 00 00 C7 ? ? ? 00 00 ? 00 00 00 89 ? ? ? 00 00 8D
const DWORD BuffCountOff = AtkCountOff + 16;
const DWORD BreathOff = 0x00000728;                   // 83 B8 ? ? ? ? 00 7E ? 6A 00 6A 00 6A 00 6A 00
const DWORD CharAnimOff = BreathOff + 4;

const DWORD MobBase = 0x016A5B84;                     // 8B ? ? ? ? ? E8 ? ? ? ? 8B ? 89 ? ? ? ? ? 0F 84 ? ? ? ? 8B [1st result]
const DWORD MobCountOff = 0x00000010;                 // 8B 52 ? 83 C7 ? 8D 44 24 ? 50 8B CF FF D2 8B 00 89
const DWORD MobDeathOff = 0x00000560;                 // 89 86 ? ? ? ? 89 86 ? ? ? ? 33 C0 89 86
const DWORD Mob1Off = 0x00000028;                     // 89 7E ? 89 7E ? ? ? ? ? ? 89 46 ? 89 46 ? 89 7E ? 89 7E ? 89 7E ? 89 ? ? 89
const DWORD Mob2Off = 0x00000004;                     // 89 7B ? 89 ? 24 ? ? ? 89
const DWORD Mob3Off = 0x0000017C;                     // 89 9E ? ? ? ? 89 9E ? ? ? ? 89 9E ? ? ? ? 89 9E ? ? ? ? 89 9E ? ? ? ? C7 86 ? ? ? ? ? ? ? ? 89 9E ? ? ? ? 89 9E ? ? ? ? 89 9E ? ? ? ? 8B
const DWORD Mob4Off = 0x00000024;                     // 89 5C ? ? C7 01 ? ? ? ? 89 59 [1st Result]
const DWORD MobXOff = 0x00000058;                     // 89 ? ? DD ? ? 39 ? ? 75 ? 6A ? 8D ? ? 00 00 00 52 ? ? E8 ? ? ? ? EB ? 33
const DWORD MobYOff = MobXOff + 4;


const DWORD MouseBase = 0x016A5C80;                   // 8B 0D ? ? ? ? 74 12 83 B9 ? ? ? ? ? 74 09 6A ? 6A ? E8
const DWORD MouseAnimOff = 0x000009E0;                // Below MouseInfoBase
const DWORD MouseLocOff = 0x00000978;                 // 8B B1 ? ? ? ? 85 F6 75 ? 68 ? ? ? ? E8 ? ? ? 00 8B 4C 24 ? 8B 06 8B 90 ? ? ? ? F7 D9
const DWORD MouseXOff = 0x0000008C;                   // 8B 88 ? ? ? ? 6A ? 57 83 C5 ? 55
const DWORD MouseYOff = MouseXOff + 4;
//int RealMouse = *((DWORD*)MouseBase) + MouseLocOff;

const DWORD ServerBase = 0x016A1230;                  // 8B ? ? ? ? ? A1 ? ? ? ? 8D ? ? ? 51 8B CD 89 44 24 ? E8 ? ? ? ? 8B 70
const DWORD WorldOff = 0x000020BC;                    // 8B 8F ? ? ? ? 8B 00 51 50 6A ? 8B CE C7 44 24 [1st Result]
const DWORD ChannelOff = WorldOff + 8;
const DWORD TubiOff = 0x00002138;                     // 83 ? ? ? ? ? 00 75 ? 83 7C ? ? 00 75 ? 8B ? ? ? ? ? 8B ? ? 51 83 C0 ? 50

const DWORD TeleportToggle = 0x00008A94;              // AOBS DONT WORK BUT OFFSETS ARE THE SAME AS LAST PATCH
const DWORD TeleportX = 0x00008AB8;                   //TeleportY + 0x0C
const DWORD TeleportY = 0x00008AAC;                   //

//Map AoB invalid
const DWORD MapBase = 0x013FCF98;                     // A1 ? ? ? ? 8B 50 ? 83 C0
const DWORD LeftWallOff = 0x0000001C;                 // Under MapInfoBase
const DWORD TopWallOff = 0x00000020;
const DWORD RightWallOff = 0x00000024;
const DWORD BottomWallOff = 0x00000028;

const DWORD MapInfoBase = 0x016A68C8;                 // 8B 0D ? ? ? ? E8 ? ? ? 00 8B 0D ? ? ? ? 85 C9 74
const DWORD MapIDOff = 0x0000136C;                    // 8B ? ? ? ? ? 50 51 8B 0D ? ? ? ? 8D ? ? ? 52 C6 84 ? ? ? ? ? 03 E8

const DWORD PeopleBase = 0x016A5B80;                  // 8B ? ? ? ? ? 50 E8 ? ? ? ? ? ? ? ? 0F 84 ? ? ? ? 39 ? ? ? ? ? 0F 85
const DWORD PeopleCountOff = 0x00000018;              // 8B ? ? ? ? 7C ? 83 ? ? 7D ? 8B ? ? ? ? ? 8B 74 ? ? ? ? 74 ? 8B ? ? 8B

const DWORD ItemBase = 0x016A6724;                    // 89 3D ? ? ? ? 8D 4E ? C7 06
const DWORD ItemCountOff = 0x00000014;                // 8B 4C 24 ? 83 C1 F8 83 F9 50 77 ? 0F ? ? ? ? ? ? FF
const DWORD ItemIDOff = 0x000085F0;                   // 89 A9 ? ? 00 00 8B 40 ? C7 44 24 ? ? ? ? ? 85 C0

const DWORD PortalBase = 0x016ABF30;                  // 8B 3D ? ? ? ? 8B 47 ? 85 C0
const DWORD PortalCountOff = 0x00000018;

#pragma endregion

typedef void (__fastcall *setMapleData_type)(DWORD dwAddress, DWORD dwEDX, DWORD dwValue);

const setMapleData_type setMapleData = reinterpret_cast<setMapleData_type>(ADDRESS_SetMapleStoryData); // 56 8B ? 8B ? ? ? ? ? 41 [3rd Result]

const DWORD *const pdwUserLocal = reinterpret_cast<const DWORD *const>(CharBase); 

int HP, MP = 0;
int charX, charY, atkCount, buffCount, breath = 0;
int mobCount, mobDeath = 0;
int mouseX, mouseY, mouseAnim = 0;
int mapID = 0;
int worldID, channel= 0;
int peopleCount = 0;
int itemCount = 0;
int leftWall, rightWall, topWall, bottomWall = 0;
int mobX, mobY = 0;

bool mouseTeleEnabled = false;
bool kamiEnabled = false;

time_t begin;
time_t end;
bool crashed = false;
struct tm *timeStruct;

bool Teleport(int nX, int nY)
{
	__try
	{
		{
			DWORD dwUserLocal = *pdwUserLocal;
			setMapleData(dwUserLocal + TeleportToggle, NULL, 0);
			setMapleData(dwUserLocal + TeleportX, NULL, nX);
			setMapleData(dwUserLocal + TeleportY, NULL, nY);
			setMapleData(dwUserLocal + TeleportToggle, NULL, 1);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}
	return true;
}

#pragma region Kami

POINT GetMonsterLocation(){
	POINT MobLoc;

	MobLoc.x = 0;
	MobLoc.y = 0;

	for(int iMonsterIndex = mobCount; iMonsterIndex > -1; iMonsterIndex--)
	{
		DWORD dwMobStruct = ReadPointer((ULONG_PTR*) MobBase, Mob1Off);
		if(iMonsterIndex > 0)
		{
			dwMobStruct = GetValue(dwMobStruct, -12);
			for (int i = 0; i < iMonsterIndex; ++i)
			{
				dwMobStruct = GetValue(dwMobStruct, 4);
			}
			dwMobStruct = GetValue(dwMobStruct, 0x14);
		}
		else { dwMobStruct = GetValue(dwMobStruct, Mob2Off); }

		if(GetValue(dwMobStruct, MobDeathOff))
		{
			dwMobStruct = GetValue(GetValue(dwMobStruct, Mob3Off), Mob4Off);

			int x = GetValue(dwMobStruct, MobXOff);
			int y = GetValue(dwMobStruct, MobYOff);

			if(x != 0 && y !=0)
			{
				MobLoc.x = x;	
				MobLoc.y = y;
				return MobLoc;
			}
		}
	}
	
	return MobLoc;
}


void kamiUpdate(){

	while(kamiEnabled){

		if(!(mobCount > 1)) continue;

		POINT loc = GetMonsterLocation();

		int nDistanceX = loc.x - charX;
		int nDistanceY = loc.y - charY;

		if (nDistanceX < 0 || nDistanceX > 50 || nDistanceY < 0 || nDistanceY > 50)
		{
			Teleport(loc.x - 50, loc.y - 10);
		}

		Sleep(25);

	}

	return;
}

#pragma endregion

#pragma region UI and Crash Time Count Updates


void updateTime(){
	//initialize begin clock.
	if(!begin && mapID!=0){
		//std::cout << "clock init" << std::endl;
		begin = time(0);
	}

	time_t elapsed_secs = 0;

	if(begin && mapID==0){
		//std::cout << "crashed" << std::endl;
		crashed = true;
		std::cout << "Crash After: "<< timeStruct->tm_hour << '.'<< timeStruct->tm_min << '.' << timeStruct->tm_sec << std::endl;
		begin = NULL;
	}	

	if(begin && !crashed){
		//std::cout << "time update" << std::endl;
		end = time(0);
		elapsed_secs = end - begin;
	}
	
	timeStruct = gmtime(&elapsed_secs);
	crashed = false; //re-init false

}

void update(){

	while(true){
		//requires bypass to write pointer
		WritePointer(AlertBase, HPAlertOff, 20);
		WritePointer(AlertBase, MPAlertOff, 20);

		HP = (int)ReadPointer((ULONG_PTR*) Stats_Base, HPOff);
		MP = (int)ReadPointer((ULONG_PTR*) Stats_Base, MPOff);

		charX = (int)ReadPointer((ULONG_PTR*) CharBase, CharXOff);
		charY = (int)ReadPointer((ULONG_PTR*) CharBase, CharYOff);
		atkCount = (int)ReadPointer((ULONG_PTR*) CharBase, AtkCountOff);
		buffCount = (int)ReadPointer((ULONG_PTR*) CharBase, BuffCountOff);
		breath = (int)ReadPointer((ULONG_PTR*) CharBase, BreathOff);

		mobCount = (int)ReadPointer((ULONG_PTR*) MobBase, MobCountOff);
		mobDeath = (int)ReadPointer((ULONG_PTR*) MobBase, MobDeathOff);

		mouseX = (int)readMultiPointer((ULONG_PTR) MouseBase, 2, MouseLocOff, MouseXOff);
		mouseY = (int)readMultiPointer((ULONG_PTR) MouseBase, 2, MouseLocOff, MouseYOff);
		mouseAnim = (int)readMultiPointer((ULONG_PTR) MouseBase, 1, MouseAnimOff);
		
		mapID = (int)ReadPointer((ULONG_PTR*) MapInfoBase, MapIDOff);

		worldID = (int)ReadPointer((ULONG_PTR*) ServerBase, WorldOff);
		channel = (int)ReadPointer((ULONG_PTR*) ServerBase, ChannelOff);

		peopleCount = (int)ReadPointer((ULONG_PTR*) PeopleBase, PeopleCountOff);

		itemCount = (int)ReadPointer((ULONG_PTR*) ItemBase, ItemCountOff);

		mobX = (int) readMultiPointer((ULONG_PTR) MobBase, 5, Mob1Off, Mob2Off, Mob3Off, Mob4Off, MobXOff);
		mobY = (int) readMultiPointer((ULONG_PTR) MobBase, 5, Mob1Off, Mob2Off, Mob3Off, Mob4Off, MobYOff);

		if(mouseTeleEnabled && mouseAnim == 12){
			Teleport(mouseX, mouseY);
		}

		updateTime();

		//debugging prints
		//std::cout << mobX << ','<< mobY<< std::endl;

		Sleep(25); //25ms delay
	}
}

#pragma endregion