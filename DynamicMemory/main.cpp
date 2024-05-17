#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int* arr, const int n);

void Print(int* arr, const int n);

int* push_back(int arr[], int& n, int value);

int* push_front(int arr[], int& n, int value);

int* pop_back(int arr[], int& n);

int* pop_front(int arr[], int& n);

void main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер масива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr=push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);
	delete[] arr;
} 

void FillRand(int* arr, const int n){
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

int* push_back(int arr[],int& n, int value) {
//создаюм буферный массив;
	int* buffer = new int[n + 1];
	//копирую\ем значени€ из исходного масcива в буферный масcив;
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}
	//удал€ем исходный маcсив; 
	delete[] arr;
	// подмен€ем адрес исходного массива адресом нового масива;
	arr = buffer;
	//только после этого в конец массива по€вл€етс€ свободное место ,
	//куда можно добавмть значение;
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;
}

int* push_front(int arr[], int& n, int value) {
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++) {
		buffer[i+1] = arr[i];
	}
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
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete arr;
	return buffer;
}