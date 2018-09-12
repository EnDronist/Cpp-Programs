//#include "stdafx.h"
#include <iostream>
#include <string>
//#include <conio.h>
using namespace std;
bool sisb(const char *text) {
	const char *str = text;
	for (;*str;str++){if(!(*str=='0'||*str=='1'))return false;}
	return true;
}// Const Char is Bool
int zeros_sequence(const char *text) {
	const char *str = text; int count = 0, max_count = 0;
	for (;*str;str++) {
		if (*str=='0'){
			count++;
			if(count>max_count) max_count = count;
		}
		else count = 0;
	}
	return max_count;
}
int main() {
	//setlocale(LC_ALL, "RUS");
	string text;
	cout<<"Enter a sequence of zeros and ones: ";
	back: cin>>text; if(!(sisb(text.c_str()))){cout<<"Enter a valid sequence ('0' and '1' symbols): "; goto back;}
	cout<<"Maximum zeros' length in a row: "<<zeros_sequence(text.c_str())<<endl;
	system("pause");
	return 0;
}