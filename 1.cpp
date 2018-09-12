//#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
//#include <conio.h>
using namespace std;
bool sisd(const char *text) {
	bool point = false;
	const char*str = text;
	if (*str <= 255 && *str >= -1){if (*str == '-')str++;}else return false;
	if (*str&&*str<=255&&*str>=-1) { if (*str == '.')return false; }else return false;
	for (; *str; str++) {
		if (!(*str <= 255 && *str >= -1)) return false;
		if (*str == '.'&&point == true)return false;
		if (*str == '.'&&point == false)point = true;
		if (!((isdigit(*str)) || *str == '.'))return false;
	}
	str--; if (*str == '.') { return false; }
	return true;
}// Const Char is Double
/*const char *strcatn(const char *n, ...)
{
	const char *address=n;
	int len = 0;
	while (*address) {len += strlen(*address); address++; }
	char *str = new char[len + 1];
	str[0] = 0;
	address = &n;
	while (*n) {
		strcat_s(str, len, *address);
		address++;
	}
	return str;
}*/
class point {
public:
	double x, y;
	point() {
		this->x = 0;
		this->y = 0;
	}
	point(double x, double y){
		this->x = x;
		this->y = y;
	}
	string print() {
		stringstream double_x,double_y;
		double_x << this->x; double_y << this->y;
		string text = "("+ double_x.str() +";"+ double_y.str() +")";
		return text;
	}
	double ratio() {
		return this->y / this->x;
	}//Отношение изменения значения функции (y) при изменении аргумента (x) для вектора
	point operator + (point kek) {
		point tmp;
		tmp.x = this->x + kek.x;
		tmp.y = this->y + kek.y;
		return tmp;
	}
	point operator += (point kek) {
		point tmp = *this + kek;
		return tmp;
	}
	point operator - (point kek) {
		point tmp;
		tmp.x = this->x - kek.x;
		tmp.y = this->y - kek.y;
		return tmp;
	}
	point operator -= (point kek) {
		point tmp = *this - kek;
		return tmp;
	}
	point operator * (double kek) {
		point tmp;
		tmp.x = this->x * kek;
		tmp.y = this->y * kek;
		return tmp;
	}
	point operator *= (double kek) {
		point tmp = (*this) * (kek);
		return tmp;
	}
	point operator / (double kek) {
		point tmp;
		tmp.x = this->x / kek;
		tmp.y = this->y / kek;
		return tmp;
	}
	point operator /= (double kek) {
		point tmp = (*this) / (kek);
		return tmp;
	}
	point operator = (point kek) {
		this->x = kek.x;
		this->y = kek.y;
		return (*this);
	}
};
int main() {
	//setlocale(LC_ALL, "RUS");
	//Ввод координат первой точки
	string string_x, string_y;
	return_to_first:
	do { cout << "Enter x,y for first point of triangle: "; cin >> string_x >> string_y; } while (!(sisd(string_x.c_str()) && sisd(string_y.c_str())));
	point p1(stod(string_x),stod(string_y));
	//Ввод координат второй точки
	return_to_second:
	do { cout << "Enter x,y for second point of triangle: "; cin >> string_x >> string_y; } while (!(sisd(string_x.c_str()) && sisd(string_y.c_str())));
	if (stod(string_x.c_str()) == stod(to_string(p1.x).c_str()) && stod(string_y.c_str()) == stod(to_string(p1.y).c_str())) { cout << "Enter another coordinates then in the first.\n"; goto return_to_second; }
	point p2(stod(string_x), stod(string_y));
	//Ввод координат третьей точки
	return_to_third:
	do { cout << "Enter x,y for third point of triangle: "; cin >> string_x >> string_y; } while (!(sisd(string_x.c_str()) && sisd(string_y.c_str())));
	if (stod(string_x.c_str()) == stod(to_string(p1.x).c_str()) && stod(string_y.c_str()) == stod(to_string(p1.y).c_str())) { cout << "Enter another coordinates then in the first.\n"; goto return_to_third; }
	if (stod(string_x.c_str()) == stod(to_string(p2.x).c_str()) && stod(string_y.c_str()) == stod(to_string(p2.y).c_str())) { cout << "Enter another coordinates then in the second.\n"; goto return_to_third; }
	point p3(stod(string_x), stod(string_y));
	if (((p2 - p1).x == 0 && (p3 - p2).x == 0) || ((p2 - p1).ratio() == (p3 - p2).ratio())) { cout << "Enter a valid triangle\n"; goto return_to_first; }
	//Вывод характеристик треугольника
	cout << "\nTriangle: (" << p1.x << ";" << p1.y << "), (" << p2.x << ";" << p2.y << "), (" << p3.x << ";" << p3.y << ")" << endl;
	//Ввод координат своей точки
	do { cout << "\nEnter x,y for your point: "; cin >> string_x >> string_y; } while (!(sisd(string_x.c_str()) && sisd(string_y.c_str())));
	//Проверка принадлежности пользовательской точки нужным полуплоскостям от сторон треугольника
	point pmy(stod(string_x), stod(string_y));
	point vector12 = (p2 - p1), vector23 = (p3 - p2), vector31 = (p1 - p3), vectormy;
	//cout << "\nVectors: A- " << vector12.print() << " -B- " << vector23.print() << " -C- " << vector31.print() << " -A\n";
	int correct_sides = 0;
	for (int i = 1; i <= 3; i++) {
		//cout << "From p1 to pmy: " << (pmy - p1).print() << endl;
		//cout << "Vector: " << vector12.print() << endl;
		if (vector12.x != 0) {
			if (vector31.x == 0) {
				if (p3.y > p1.y) {
					if ((pmy - p1).x == 0) { if (pmy.y >= p1.y) correct_sides++; }
					else if ((pmy - p1).x > 0) { if (vector12.ratio() <= (pmy - p1).ratio()) correct_sides++; }
					else if (vector12.ratio() >= (pmy - p1).ratio()) correct_sides++;
				}
				else {
					if ((pmy - p1).x == 0) { if (pmy.y <= p1.y) correct_sides++; }
					else if ((pmy - p1).x > 0) { if (vector12.ratio() >= (pmy - p1).ratio()) correct_sides++;}
					else if (vector12.ratio() <= (pmy - p1).ratio()) correct_sides++;
				}
			}
			else if (vector12.ratio() > vector31.ratio()) {
				if ((pmy - p1).x == 0) {
					if (vector31.x < 0) { if (pmy.y <= p1.y) correct_sides++; }
					else if (pmy.y >= p1.y) correct_sides++;
				}
				else {
					if ((vector31.x < 0) ^ ((pmy - p1).x > 0)) { if (vector12.ratio() <= (pmy - p1).ratio()) correct_sides++; }
					else if (vector12.ratio() >= (pmy - p1).ratio()) correct_sides++;
				}
			}
			else if (vector12.ratio() < vector31.ratio()) {
				if ((pmy - p1).x == 0) {
					if (vector31.x < 0) { if (pmy.y >= p1.y) correct_sides++; }
					else if (pmy.y <= p1.y) correct_sides++;
				}
				else {
					if ((vector31.x < 0) ^ ((pmy - p1).x > 0)) { if (vector12.ratio() >= (pmy - p1).ratio()) correct_sides++; }
					else if (vector12.ratio() <= (pmy - p1).ratio()) correct_sides++;
				}
			}
		}
		else {
			if (pmy.x == p1.x) correct_sides++;
			else if (p3.x > p1.x && pmy.x >= p1.x) correct_sides++;
			else if (p3.x < p1.x && pmy.x <= p1.x) correct_sides++;
		}
		//Перестановка переменных
		swap(p1,p3);swap(p1,p2);
		swap(vector12,vector31);swap(vector12,vector23);
	}
	if (correct_sides == 3) cout << "Point in the triangle.\n";
	else cout << "Point not in the triangle. Number of lines, when point on correct side: " << correct_sides << endl;
	system("pause");
	return 0;
}