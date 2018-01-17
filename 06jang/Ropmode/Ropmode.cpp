#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass="RopMode";

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

	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
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
	static int sx,sy,oldx,oldy;
	int ex,ey;
	static BOOL bNowDraw = FALSE;
	HDC hdc;
	switch(iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		oldx = sx;
		oldy = sy;
		bNowDraw = TRUE;
		return 0;
	case WM_LBUTTONUP:
		bNowDraw = FALSE;
		hdc=GetDC(hWnd);
		MoveToEx(hdc,sx,sy,NULL);
		LineTo(hdc,oldx,oldy);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_MOUSEMOVE:
		if (bNowDraw) {
			hdc=GetDC(hWnd);
			SetROP2(hdc,R2_NOT);
			MoveToEx(hdc,sx,sy,NULL);
			LineTo(hdc,oldx,oldy);
			ex = LOWORD(lParam);
			ey = HIWORD(lParam);
			MoveToEx(hdc,sx,sy,NULL);
			LineTo(hdc,ex,ey);
			oldx = ex;
			oldy = ey;
			ReleaseDC(hWnd,hdc);
		}
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}
