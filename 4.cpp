#include "stdafx.h"
#include <iostream>
#include <string>
//#include <conio.h>
using namespace std;
bool sisi(const char *text) {
	const char *str = text;
	if(*str == '-') str++;
	for(; *str; str++) {
		if(!(*str <= 255 && *str >= -1)) return false;
		if(!(isdigit(*str)))return false;
	}
	str--; if(*str == '-') { return false; }
	return true;
}// Const Char is Integer
int main() {
	//setlocale(LC_ALL, "RUS");
	string a_t, b_t, c_t; int a, b, c, z;
	cout<<"Enter values to a,b,c: ";
	back: cin>>a_t>>b_t>>c_t; if(!(sisi(a_t.c_str())&&sisi(b_t.c_str())&&sisi(c_t.c_str()))){cout<<"Enter a valid numbers: "; goto back;}
	a = stoi(a_t); b = stoi(b_t); c = stoi(c_t);
	cout<<"Finding max (min ("<<a<<", "<<b<<"), "<<c<<"):\n";
	if(a<b){if(a>c)z=a;else z=c;}else if(b>c)z=b;else z=c;
	cout<<"Answer: "<<z<<endl;
	system("pause");
	return 0;
}