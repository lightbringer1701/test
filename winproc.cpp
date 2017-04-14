//	winproc.cpp

#include "main.h"

char sztemp[32];

LRESULT APIENTRY MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	
	static int	flag_mod = 0;	// 0 - start; 1 - edit test; 2 - server.
	
	static Ques	**QuesArray;	// Дин. массив вопросов
	static int	sizeQues = 0;	// Число вопросов
	static int	**idQues;		// Дин. массив ID кнопок "Delete"
		
	HINSTANCE	hinst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);	// Дескриптор приложения
	HMENU	MainMenu = GetMenu(hWnd);									// Дескриптор главного меню
	HMENU	TestMenu = GetSubMenu(MainMenu, 1);							// Дескриптор сабменю Test
	int	i, j, k;														// Переменные для циклов
	bool	MyBool;
	
	switch(message) {
		case WM_CLOSE: {
			PostQuitMessage(0);
		}
		case WM_CREATE: {
		
			break;		
		}
		case WM_COMMAND: {
			switch (LOWORD(wParam)) {
				case ID_MENU_10: {											// Test -> New 
					if (flag_mod != 1) {
						QuesArray = AddQues(QuesArray, sizeQues, STARTFREEID, hWnd, hinst);	// Создаем 
						idQues = AddInt(idQues, sizeQues, STARTFREEID);						// ... первый
						sizeQues++;															// ... вопрос
						SetWindowText(hWnd, TITLEMODEDIT);					// Меняем заголовок окна
						flag_mod = 1;										// Устанавливаем флаг на редактор теста
						EnableMenuItem(TestMenu, ID_MENU_16, MF_ENABLED);	// Активируем кнопку меню 
					}
					break;
				}
				case ID_MENU_16: {											// Test -> New Question
					if (flag_mod == 1) {
						// Ищем свободный ID для новой кнопки
						k = STARTFREEID;
						j = 0;
						while (j == 0) {
							MyBool = false;
							for (i = 0; i < sizeQues; i++) {
								if (QuesArray[i][0].id == k) {
									MyBool = true;
									break;
								}
							}
							if (MyBool == true) {
								k++;
							} else {
								j = k;
							}
						}
						// Добавляем кнопку
						QuesArray = AddQues(QuesArray, sizeQues, j, hWnd, hinst);
						idQues = AddInt(idQues, sizeQues, j);
						sizeQues++;
					}
					break;
				}
			}
			// Поиск на нажатие Delete
			for (i = 0; i < sizeQues; i++) {
				if (LOWORD(wParam) == QuesArray[i][0].id) {
					QuesArray = DeleteQues(QuesArray, sizeQues, i+1, hWnd, hinst);
					idQues = DeleteInt(idQues, sizeQues, i+1);
					sizeQues--;
				}
			}
			break;
		}
		case WM_KEYDOWN: {
			switch (LOWORD(wParam)) {
				case VK_F2: {
					if (flag_mod == 1) {
						// Ищем свободный ID для новой кнопки
						k = STARTFREEID;
						j = 0;
						while (j == 0) {
							MyBool = false;
							for (i = 0; i < sizeQues; i++) {
								if (QuesArray[i][0].id == k) {
									MyBool = true;
									break;
								}
							}
							if (MyBool == true) {
								k++;
							} else {
								j = k;
							}
						}
						// Добавляем кнопку
						QuesArray = AddQues(QuesArray, sizeQues, j, hWnd, hinst);
						idQues = AddInt(idQues, sizeQues, j);
						sizeQues++;
					}
					break;
				}
			}
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}