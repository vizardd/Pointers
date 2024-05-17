#include<iostream>
using namespace std;

#define tab "\t"



void FillRand(int* arr, const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);

int* push_front(int arr[], int& n, int value);

int* pop_back(int arr[], int& n);

int* pop_front(int arr[], int& n);

int* insert(int* arr, int& n, int value, int index);

int* erease(int* arr, int& n, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main() {
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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
#endif //DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	//Создаюм массив указатей
	int** arr = new int* [rows];
	//Выделяем память под строки
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols] {};
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	//сначала удаляем строки
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	//удаляем массив
	delete arr;
#endif //DYNAMIC_MEMORY_2
}

void FillRand(int* arr, const int n) {
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)

{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}

}

void Print(int* arr, const int n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value) {
	//создаюм буферный массив;
	int* buffer = new int[n + 1];
	//копируюем значения из исходного масcива в буферный масcив;
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