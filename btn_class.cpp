#include "main.h"

static stringstream		strS;
static string			S;

char ssa[32];

// Конструктор класса Ques
Ques::Ques(HWND WND, HINSTANCE HINST, int ID, int height) {
	id = ID;
	h = height;
	strS << ID; 
	strS >> S;
	itoa(id, ssa, 10);
	MessageBoxA(NULL, ssa, "Test", MB_ICONINFORMATION);
	BtnDel = CreateWindow("BUTTON", "Delete", BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP, 700, height, 70, 20, WND, (HMENU)ID, HINST, NULL);
	SendMessage(BtnDel, WM_SETFONT, (WPARAM)GetNewFont(), TRUE);
	EditTitle = CreateWindow("Edit", S.c_str(), DWORD(WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE | ES_MULTILINE), 100, height+30, 670, 40, WND, NULL, HINST, 0);
	SendMessage(EditTitle, WM_SETFONT, (WPARAM)GetNewFont(), TRUE);
}
// Деструктор класса Ques
Ques::~Ques() {
	DestroyWindow(BtnDel);
	DestroyWindow(EditTitle);
}
// Функция создания нового элемента Ques
Ques **AddQues(Ques **array, int size, int id, HWND wnd, HINSTANCE hinst) {
	Ques **copy;
	int i;
	if (size == 0) {
		array = new Ques*[size+1];
	} else {
		copy = new Ques*[size+1];
		for (i = 0; i < size; i++)
			copy[i] = array[i];
		delete[] array;
		array = new Ques*[size+1];
		for (i = 0; i < size; i++)
			array[i] = copy[i];
		delete[] copy;
		}
	array[size] = new Ques(wnd, hinst, id, size*QUESHEIGHT);
	return array;
}
// Функция удаления элемента Ques
Ques **DeleteQues(Ques **array, int size, int index, HWND wnd, HINSTANCE hinst) {
	Ques **copy;
	int i;
	copy = new Ques*[size-1];
	for (i = 0; i < index-1; i++)
		copy[i] = array[i];
	for (i = index-1; i < size-1; i++) {
		copy[i] = array[i+1];
		MoveWindow(copy[i][0].BtnDel, 700, copy[i][0].h - QUESHEIGHT, 70, 20, true);
		MoveWindow(copy[i][0].EditTitle, 100, copy[i][0].h - QUESHEIGHT + 30, 670, 40, true);
		copy[i][0].h = copy[i][0].h - QUESHEIGHT;
		//SetWindowLong(copy[i][0].BtnDel, GWL_ID, copy[i][0].id-1);
		//copy[i][0].id--;
	}	
	delete array[index-1];
	delete[] array;
	array = new Ques*[size-1];
	for (i = 0; i < size-1; i++)
		array[i] = copy[i];
	delete[] copy;
	
	return array;
}