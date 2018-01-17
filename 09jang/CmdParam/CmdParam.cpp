#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
		  ,LPSTR lpszCmdParam,int nCmdShow)
{
	MessageBox(NULL, lpszCmdParam, "CmdParam", MB_OK);
	return 0;
}