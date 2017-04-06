#include "main.h"

int sizeQues = 0;
Ques **QuesArray;

LRESULT APIENTRY MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HINSTANCE hinst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
	int i;
	switch(message) {
		case WM_CLOSE: {
			PostQuitMessage(0);
		}
		case WM_CREATE: {
			
			break;		
		}
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
				case ID_MENU_10: {
					QuesArray = AddQues(QuesArray, sizeQues, sizeQues+4000, hWnd, hinst);
					sizeQues++;
					break;
				}
			}
			for (i = 4000; i < sizeQues+4000; i++) {
				if (LOWORD(wParam) == i) {
					QuesArray = DeleteQues(QuesArray, sizeQues, i-3999, hWnd, hinst);
					sizeQues--;
				}
			}
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}