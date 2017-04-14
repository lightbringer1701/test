#include "main.h"

int **AddInt(int **array, int size, int newint) {
	int **copy;
	int i;
	if (size == 0) {
		array = new int*[size+1];
	} else {
		copy = new int*[size+1];
		for (i = 0; i < size; i++)
			copy[i] = array[i];
		delete[] array;
		array = new int*[size+1];
		for (i = 0; i < size; i++)
			array[i] = copy[i];
		delete[] copy;
		}
	array[size] = new int;
	array[size][0] = newint;
	return array;
};

int **DeleteInt(int **array, int size, int index) {
	int **copy;
	int i;
	copy = new int*[size-1];
	for (i = 0; i < index-1; i++)
		copy[i] = array[i];
	for (i = index-1; i < size-1; i++)
		copy[i] = array[i+1];
	delete array[index-1];
	delete[] array;
	array = new int*[size-1];
	for (i = 0; i < size-1; i++)
		array[i] = copy[i];
	delete[] copy;
	
	return array;
}