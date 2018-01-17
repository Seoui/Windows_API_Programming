#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass="TextOut";

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
		  ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=(WNDPROC)WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd=CreateWindow(lpszClass,"My First Program",WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		  CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		  NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	
	while(GetMessage(&Message,0,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt={100,100,400,300};
	char str[]="´ÔÀº °¬½À´Ï´Ù. ¾Æ¾Æ »ç¶ûÇÏ´Â ³ªÀÇ ´ÔÀº °¬½À´Ï´Ù. Çª¸¥ »êºûÀ» "
		"±úÄ¡°í ´ÜÇ³³ª¹« ½£À» ÇâÇÏ¿© ³­ ÀÛÀº ±æÀ» °É¾î¼­ Â÷¸¶ ¶³Ä¡°í °¬½À´Ï´Ù."
		"È²±ÝÀÇ ²É°°ÀÌ ±»°í ºû³ª´ø ¿¾ ¸Í¼¼´Â Â÷µðÂù Æ¼²øÀÌ µÇ¾î ÇÑ¼ûÀÇ ¹ÌÇ³¿¡"
		"³¯¾Æ°¬½À´Ï´Ù.";
	switch(iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		hdc=BeginPaint(hWnd,&ps);
		DrawText(hdc,str,-1,&rt,DT_CENTER | DT_WORDBREAK);
//		SetTextAlign(hdc, TA_CENTER);
//		TextOut(hdc,200,60,"Beautiful Korea",15);
//		TextOut(hdc,200,80,"is",2);
//		TextOut(hdc,200,100,"My Lovely Home Country",22);
		EndPaint(hWnd,&ps);
		return 0;
/*	case WM_LBUTTONDOWN:
		hdc=GetDC(hWnd);
		TextOut(hdc,100,100,"Beautiful Korea",15);
		ReleaseDC(hWnd, hdc);
		return 0;
		*/
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}
