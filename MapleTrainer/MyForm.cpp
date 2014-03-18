#include "MyForm.h"
#include <iostream>

using namespace MyDllApp; 

extern int HP, MP;
extern int charX, charY, atkCount,buffCount, breath;
extern int mobCount, mobDeath, mapID, worldID, channel, peopleCount, itemCount;
extern int mouseX, mouseY, mouseAnim;
extern bool mouseTeleEnabled;
extern bool kamiEnabled;
extern void kamiUpdate();
extern struct tm *timeStruct;

[STAThreadAttribute]

int Main(){
    // Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    // Create the main window and run it
    Application::Run(gcnew MyForm()); //Form1 is the name of the form created. 
    //if named different replace Form1 With the right form name.
    return 0;
}

bool ExitMapleStory() {
	HWND hWnd = FindWindow(0, L"MapleStory");//get maplestory window
	if (hWnd == 0) {
		return false;//return false if maplestory is not found
	} else {
		DWORD pID;//process id
		GetWindowThreadProcessId(hWnd, &pID);//getting the process id
		HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);//opening the process
		PostThreadMessage(pID, WM_CLOSE, 0, 0);//posting a message to close maplestory
		WaitForSingleObject(pHandle, 2000);//wait for 2 seconds waiting for maplestory to close

		DWORD exit = 0;//exit code
		GetExitCodeProcess(pHandle, &exit);//get the exit code
		if (exit == STILL_ACTIVE) {
			TerminateProcess(pHandle, 0);//if maplestory doesnt exit destroy the process
		}
		CloseHandle(pHandle);//close the process handle
		return true;
	}
}


void MyForm::onButton1Click(System::Object^  sender, System::EventArgs^  e)
{
	ExitMapleStory();
}

void MyForm::onTimer1(System::Object ^sender, System::EventArgs ^e)
{
    MyForm::HP_VAL->Text = HP.ToString();
	MyForm::MP_VAL->Text = MP.ToString();
	MyForm::CHARX_VAL->Text = charX.ToString();
	MyForm::CHARY_VAL->Text = charY.ToString();
	MyForm::ATTACKCOUNT_VAL->Text = atkCount.ToString();
	MyForm::BREATH_VAL->Text = breath.ToString();	
	MyForm::MOBCOUNT_VAL->Text = mobCount.ToString();
	MyForm::MAPID_VAL->Text = mapID.ToString();
	MyForm::WORLDID_VAL->Text = worldID.ToString();
	MyForm::CHANNEL_VAL->Text = (channel+1).ToString();
	MyForm::PEOPLECOUNT_VAL->Text = peopleCount.ToString();
	MyForm::ITEMCOUNT_VAL->Text = itemCount.ToString();
	MyForm::MOUSEX_VAL->Text = mouseX.ToString();
	MyForm::MOUSEY_VAL->Text = mouseY.ToString();
	MyForm::MOUSEANIM_VAL->Text = mouseAnim.ToString();
	MyForm::TEST_LABEL->Text = (timeStruct->tm_hour).ToString() + ":"+ (timeStruct->tm_min) + ":" + (timeStruct->tm_sec);
}

void MyForm::mouseTeleChangedCheck(System::Object ^sender, System::EventArgs ^e){
	if (MOUSE_TELE->Checked)
		mouseTeleEnabled = true;
	else
		mouseTeleEnabled = false;
}

void MyForm::kamiChanged(System::Object ^sender, System::EventArgs ^e){
	if (KAMI_TOGGLE->Checked){
		kamiEnabled = true;
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)kamiUpdate, NULL, 0, NULL);
	}
	else
		kamiEnabled = false;
}