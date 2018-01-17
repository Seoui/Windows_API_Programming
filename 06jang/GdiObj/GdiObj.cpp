#include <windows.h>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass="GdiObj";

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
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH MyBrush,OldBrush;
	HPEN MyPen, OldPen;
	switch(iMessage) {
	case WM_PAINT:
		hdc=BeginPaint(hWnd,&ps);
		MyBrush=CreateHatchBrush(HS_BDIAGONAL, RGB(255,255,0));
		OldBrush=(HBRUSH)SelectObject(hdc,MyBrush);
		MyPen=CreatePen(PS_SOLID, 5, RGB(0,0,255));
		OldPen=(HPEN)SelectObject(hdc, MyPen);
		Rectangle(hdc,50,50,300,200);
		SelectObject(hdc,OldBrush);
		SelectObject(hdc, OldPen);
		DeleteObject(MyBrush);
		DeleteObject(MyPen);
		EndPaint(hWnd,&ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

/* ∆Ê øπ¡¶
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HPEN MyPen, OldPen;
	switch(iMessage) {
	case WM_PAINT:
		hdc=BeginPaint(hWnd,&ps);
		MyPen = CreatePen(PS_SOLID, 5, RGB(0,0,255));
		OldPen = (HPEN)SelectObject(hdc, MyPen);
		Rectangle(hdc,50,50,300,200);
		SelectObject(hdc, OldPen);
		DeleteObject(MyPen);
		EndPaint(hWnd,&ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}
*/

/* Ω∫≈Â ∫Í∑ØΩ√ øπ¡¶
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH MyBrush,OldBrush;
	switch(iMessage) {
	case WM_PAINT:
		hdc=BeginPaint(hWnd,&ps);
		MyBrush=(HBRUSH)GetStockObject(GRAY_BRUSH);
		OldBrush=(HBRUSH)SelectObject(hdc,MyBrush);
		Rectangle(hdc,50,50,300,200);
		SelectObject(hdc,OldBrush);
		EndPaint(hWnd,&ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}
*/