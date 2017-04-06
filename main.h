#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>

#define ID_MYMENU_0 100

#define ID_MENU_0	110
#define ID_MENU_1	111
#define ID_MENU_2	112
#define ID_MENU_3	113
#define ID_MENU_4	114
#define ID_MENU_5	115
#define ID_MENU_6	116

#define ID_MENU_10	120
#define ID_MENU_11	121
#define ID_MENU_12	122
#define ID_MENU_13	123
#define ID_MENU_14	124
using namespace std;

class Ques {
	public:
		int id;
		int h;
		HWND BtnDel;
		Ques(HWND WND, HINSTANCE HINST, int ID, int height);
		~Ques();
};

LRESULT APIENTRY MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

Ques **AddQues(Ques **array, int size, int id, HWND wnd, HINSTANCE hinst);
Ques **DeleteQues(Ques **array, int size, int index, HWND wnd, HINSTANCE hinst);