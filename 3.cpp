//#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
//#include <conio.h>
using namespace std;
bool sisd(const char *text) {
	bool point = false;
	const char*str = text;
	if (*str <= 255 && *str >= -1) { if (*str == '-')str++; }
	else return false;
	if (*str && *str <= 255 && *str >= -1) { if (*str == '.')return false; }
	else return false;
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
	//Ввод числа для проверки
	string text;
	cout << "Enter the number: ";
	back: cin >> text;if (!sisd(text.c_str())) { cout << "Enter a valid number: "; goto back; }
	//Нахождение первых 8-и простых чисел, равных 2^x-1 (следующие совершенные числа больше максимального значения типа double)
	//cout << "Finding first 8 prime numbers, equal (2^x-1):\n";
	double number = stod(text), prime_numbers[8], current_prime = 1; int prime_count = 0;
	do{
		current_prime*=2;
		bool is_prime = false;
		for (double i = 2; i <= current_prime-1; i++) {
			if (fmod(current_prime-1, i)==0) break;
			if (i == current_prime - 2) { is_prime = true; }
		}
		if (is_prime) {
			prime_numbers[prime_count++] = current_prime-1;
			//cout << prime_count << ": " << prime_numbers[prime_count-1]<<endl;
		}
	} while (prime_count < 7);
	//Подсчёт восьмого числа требует минуты ожидания
	prime_numbers[prime_count] = pow(2, 31) - 1; prime_count++;
	//cout << prime_count << ": " << prime_numbers[prime_count - 1] << endl;
	//Проверка введённого значения на совершенное число
	for (int i = 0; i < prime_count; i++) {
		if (number == (((prime_numbers[i] + 1) / 2)*prime_numbers[i])) { cout << "\nValue is a perfect number.\n"; break; }
		else if (i == prime_count - 1) cout << "\nValue isn't a perfect number.\n";
	}
	system("pause");
	return 0;
}