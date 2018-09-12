//#include "stdafx.h"
#include <iostream>
#include <string>
//#include <conio.h>
using namespace std;
double *double_incsize(double *arr, int current_size)
{
	double *new_arr = new double[++current_size];
	for (int i = 0; i < current_size; i++)
		new_arr[i] = arr[i];
	delete[] arr;
	return new_arr;
}// Increases double's array size by 1
bool sisd(const char *text) {
	bool point = false;
	const char*str = text;
	if (*str <= 255 && *str >= -1) { if (*str == '-')str++; }else return false;
	if (*str && *str <= 255 && *str >= -1) { if (*str == '.')return false; }else return false;
	for (; *str; str++) {
		if (!(*str <= 255 && *str >= -1)) return false;
		if (*str == '.'&&point == true)return false;
		if (*str == '.'&&point == false)point = true;
		if (!((isdigit(*str)) || *str == '.'))return false;
	}
	str--; if (*str == '.') { return false; }
	return true;
}// Const Char is Double
int main() {
	//setlocale(LC_ALL, "RUS");
	//Ввод данных
	cout << "Enter any number of numeric values.\nWhen you want to finish the array, send the '+' symbol.\n";
	string text; double *doubles = new double[0]; int count = 0;
	do {
		back:
		cin >> text;
		if (!sisd(text.c_str()) && text != "+") { cout << "Enter a valid number.\n"; goto back; }
		if (text != "+") {
			doubles = double_incsize(doubles, count);
			doubles[count++] = stod(text);
		}
	} while (text != "+");
	cout << "Initial Array: [";
	for (int i = 0; i < count; i++) { cout << doubles[i]; if (!(i + 1 == count))cout << ", "; }
	cout << "]\n";
	//Перемещение значений в массиве
	double *new_doubles = new double[count]; int new_count=0;
	for (int i = 0; i < count; i++) { if (doubles[i] < 0)new_doubles[new_count++] = doubles[i]; }
	for (int i = 0; i < count; i++) { if (doubles[i] == 0)new_doubles[new_count++] = doubles[i]; }
	for (int i = 0; i < count; i++) { if (doubles[i] > 0)new_doubles[new_count++] = doubles[i]; }
	delete[] doubles;
	cout << "New Array: [";
	for (int i = 0; i < new_count; i++) { cout << new_doubles[i]; if (!(i + 1 == new_count))cout << ", "; }
	cout << "]\n";
	system("pause");
	return 0;
}