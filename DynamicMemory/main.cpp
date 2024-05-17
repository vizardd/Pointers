#include<iostream>
using namespace std;

#define tab "\t"



void FillRand(int* arr, const int n);

void Print(int* arr, const int n);

int* push_back(int arr[], int& n, int value);

int* push_front(int arr[], int& n, int value);

int* pop_back(int arr[], int& n);

int* pop_front(int arr[], int& n);

int* insert(int* arr, int& n, int value, int index);

int* erease(int* arr, int& n, int index);

void main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер масива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value,index;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс куда вставить значение: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << "Введите индекс удаляемого значение: "; cin >> index;
	arr = erease(arr, n, index);
	Print(arr, n);
	delete[] arr;
}

void FillRand(int* arr, const int n) {
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 100;
	}
}

void Print(int* arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value) {
	//создаюм буферный массив;
	int* buffer = new int[n + 1];
	//копирую\ем значения из исходного масcива в буферный масcив;
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	//удаляем исходный маcсив; 
	delete[] arr;
	// подменяем адрес исходного массива адресом нового масива;
	arr = buffer;
	//только после этого в конец массива появляется свободное место ,
	//куда можно добавмть значение;
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;
}

int* push_front(int arr[], int& n, int value) {
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++) buffer[i + 1] = arr[i];
	delete arr;
	buffer[0] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n) {
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete arr;
	return buffer;
}
int* pop_front(int arr[], int& n) {
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete arr;
	return buffer;
}


int* insert(int* arr, int& n, int value, int index) {
	int* buffer = new int[++n];
	for (int i = 0, j = 0; i < n; i++)
	{
		if (i != index)
			buffer[i] = arr[j++];
		else
			buffer[i] = value;
	}
	delete[] arr;
	return buffer;
}


int* erease(int* arr, int& n, int index) {
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
		for (int i = index; i < n; i++)buffer[i] = buffer[i + 1];
		n--;
	delete[] arr;
	return buffer;
}