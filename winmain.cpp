#include "main.h"

HWND		MainWnd;
int			MainWndWeith = 640;
int			MainWndHeight = 720;
HINSTANCE	hinst;

int APIENTRY WinMain(HINSTANCE hCurrentInst, HINSTANCE hPreviousInst, LPSTR lpszCmdLine, int nCmdShow) {
	WNDCLASS wndClass;	
    MSG msg;
	
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = MainWndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hCurrentInst;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
    wndClass.lpszMenuName = MAKEINTRESOURCE(ID_MYMENU_0);
    wndClass.lpszClassName = "win";
    RegisterClass(&wndClass);
	
	MainWnd = CreateWindow("win", "Test (server)",
	WS_OVERLAPPED | WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_CAPTION | WS_VSCROLL | WS_MINIMIZEBOX,
	CW_USEDEFAULT, CW_USEDEFAULT, MainWndWeith, MainWndHeight,
	NULL, NULL, hCurrentInst, NULL);
	
	HMENU MainMenu = CreateMenu();
	HMENU hPopMenuServer = CreatePopupMenu();
	HMENU hPopMenuTest = CreatePopupMenu();
	
	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT_PTR)hPopMenuServer, "Server");
	{
		AppendMenu(hPopMenuServer, MF_STRING, (int)ID_MENU_0, "Start Server");
		AppendMenu(hPopMenuServer, MF_STRING | MF_DISABLED, (int)ID_MENU_1, "Stop Server");
		AppendMenu(hPopMenuServer, MF_SEPARATOR, (int)ID_MENU_2, "");
		AppendMenu(hPopMenuServer, MF_STRING, (int)ID_MENU_3, "Options Server");
		AppendMenu(hPopMenuServer, MF_STRING | MF_DISABLED, (int)ID_MENU_4, "Client List");
		AppendMenu(hPopMenuServer, MF_SEPARATOR, (int)ID_MENU_5, "");
		AppendMenu(hPopMenuServer, MF_STRING, (int)ID_MENU_6, "Exit");
	}
	AppendMenu(MainMenu, MF_STRING | MF_POPUP, (UINT_PTR)hPopMenuTest, "Test");
	{
		AppendMenu(hPopMenuTest, MF_STRING, (int)ID_MENU_10, "New");
		AppendMenu(hPopMenuTest, MF_STRING, (int)ID_MENU_11, "Open");
		AppendMenu(hPopMenuTest, MF_SEPARATOR, (int)ID_MENU_12, "");
		AppendMenu(hPopMenuTest, MF_STRING | MF_DISABLED, (int)ID_MENU_13, "Save");
		AppendMenu(hPopMenuTest, MF_STRING | MF_DISABLED, (int)ID_MENU_14, "Save As");
	}
	DrawMenuBar(MainWnd);
	SetMenu(MainWnd, MainMenu);
	SetMenu(MainWnd, hPopMenuServer);
	SetMenu(MainWnd, hPopMenuTest);
	
	//HWND MainWndBtm1 = CreateWindow("BUTTON", "Create Btn", BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP, 10, 10, 90, 40, MainWnd, (HMENU)ID_BUTTON_0, hinst, NULL);
	
	ShowWindow(MainWnd, nCmdShow);
	UpdateWindow(MainWnd);
	
	while(GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg); 
		DispatchMessage(&msg); 
	}
	DestroyWindow (MainWnd);
	return msg.wParam;
	
}