#include "main.h"

Ques::Ques(HWND WND, HINSTANCE HINST, int ID, int height) {
	BtnDel = CreateWindow("BUTTON", "Delete", BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP, 10, height, 100, 40, WND, (HMENU)ID, HINST, NULL);
	id = ID;
	h = height;
}

Ques::~Ques() {
	DestroyWindow(BtnDel);
}

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
	array[size] = new Ques(wnd, hinst, id, size*50);
	return array;
}

Ques **DeleteQues(Ques **array, int size, int index, HWND wnd, HINSTANCE hinst) {
	Ques **copy;
	int i;
	copy = new Ques*[size-1];
	for (i = 0; i < index-1; i++)
		copy[i] = array[i];
	for (i = index-1; i < size-1; i++) {
		copy[i] = array[i+1];
		MoveWindow(copy[i][0].BtnDel, 10, copy[i][0].h - 50, 100, 40, true);
		copy[i][0].h = copy[i][0].h - 50;
		SetWindowLong(copy[i][0].BtnDel, GWL_ID, copy[i][0].id-1);
		copy[i][0].id--;
	}	
	delete array[index-1];
	delete[] array;
	array = new Ques*[size-1];
	for (i = 0; i < size-1; i++)
		array[i] = copy[i];
	delete[] copy;
	
	return array;
}