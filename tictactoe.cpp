#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <conio.h>
#include <map>
#include <iterator>
#include <climits>
#include <windows.h>
#undef max
using namespace std;
HANDLE kek = GetStdHandle(STD_OUTPUT_HANDLE);
map<string, string> lang;
map<string, string> language_english() {
	setlocale(LC_ALL, "English");
	map<string, string> lang{
	{ "start_game","Start Game" },
	{ "settings","Settings" },
	{ "exit","Exit" },
	{ "choose_one","Choose one" },
	{ "current_settings","Current settings" },
	{ "name_info","Player name" },
	{ "width_info","Field width" },
	{ "height_info","Field height" },
	{ "row_info","Size of row to win" },
	{ "lang_info","Current language: English" },
	{ "name_change","Change name" },
	{ "name_enter","Enter name in Latin (Max length=100)" },
	{ "width_change","Change field width" },
	{ "width_enter","Enter width (Min=3,Max=39)" },
	{ "width_error","The width can't be less than size of row to win, if the height is already less" },
	{ "height_change","Change field height" },
	{ "height_enter","Enter height (Min=3,Max=39)" },
	{ "height_error","The height can't be less than size of row to win, if the width is already less" },
	{ "row_change","Change size of row to win" },
	{ "row_changed","Size of row to win changed to" },
	{ "row_enter","Enter value (Min=3,Max=10)" },
	{ "row_error","Size of row to win can't be more than width and height" },
	{ "lang_change","Change language" },
	{ "lang_enter","Enter value (Min=1,Max=2)" },
	{ "output_on","Clean screen after data input" },
	{ "output_off","Don't clean screen after data input" },
	{ "output_on_info","ON" },
	{ "output_off_info","OFF" },
	{ "output_info","Cleaning screen after data input" },
	{ "save","Save and quit" },
	{ "cancel","Cancel" },
	{ "settings_saved","Game settings saved" },
	{ "init_start","Initializing game settings" },
	{ "init_empty","No save file" },
	{ "init_error_name","Incorrect saved name" },
	{ "init_error_width","Incorrect saved width" },
	{ "init_error_height","Incorrect saved height" },
	{ "init_error_row","Incorrect saved size of row to win" },
	{ "init_error_ratio","Incorrect value's proportions" },
	{ "init_error_lang","Incorrect saved language number" },
	{ "init_error_output","Incorrect saved output's setting number" },
	{ "init_default","Loading default settings" },
	{ "init_done","Settings loading complete" },
	{ "game_second_name","Enter second player's name (Latin)" },
	{ "game_showing","You started the match against" },
	{ "game_showing_2","yourself" },
	{ "game_win","Player" },
	{ "game_win_2","wins" },
	{ "game_draw","Draw" },
	{ "game_enter","Enter the column and row numbers" },
	{ "game_error_used","This cell is already used" },
	};
	return lang;
}
map<string, string> language_russian() {
	setlocale(LC_ALL, "Russian");
	map<string, string> lang{
	{ "start_game","Начать Игру" },
	{ "settings","Настройки" },
	{ "exit","Выход" },
	{ "choose_one","Выберите вариант" },
	{ "current_settings","Текущие настройки" },
	{ "name_info","Имя игрока" },
	{ "width_info","Ширина поля" },
	{ "height_info","Высота поля" },
	{ "row_info","Размер в ряд для победы" },
	{ "lang_info","Текущий язык: Русский" },
	{ "name_change","Сменить имя" },
	{ "name_enter","Введите имя на латинице (Максимальная длина=100)" },
	{ "width_change","Изменить ширину поля" },
	{ "width_enter","Введите ширину (Мин.=3,Макс.=39)" },
	{ "width_error","Ширина не может быть меньше размера ряда для победы, если высота - уже меньше" },
	{ "height_change","Изменить высоту поля" },
	{ "height_enter","Введите высоту (Мин.=3,Макс.=39)" },
	{ "height_error","Высота не может быть меньше размера ряда для победы, если ширина - уже меньше" },
	{ "row_change","Изменить размер ряда для победы" },
	{ "row_changed","Размер ряда для победы изменён до" },
	{ "row_enter","Введите значение (Мин.=3,Макс.=10)" },
	{ "row_error","Размер ряда для победы не может быть больше ширины и высоты" },
	{ "lang_change","Изменить язык" },
	{ "lang_enter","Введите значение (Мин.=1,Макс.=2)" },
	{ "output_on","Очищать экран после ввода данных" },
	{ "output_off","Не очищать экран после ввода данных" },
	{ "output_on_info","ON" },
	{ "output_off_info","OFF" },
	{ "output_info","Очистка экрана после ввода данных включена" },
	{ "save","Сохранить и выйти" },
	{ "cancel","Отмена" },
	{ "settings_saved","Настройки игры сохранены" },
	{ "init_start","Инициализация настроек игры" },
	{ "init_empty","Файл сохранения отсутствует" },
	{ "init_error_name","Неверное сохранённое имя" },
	{ "init_error_width","Неверная сохранённая ширина" },
	{ "init_error_height","Неверная сохранённая высота" },
	{ "init_error_row","Неверный размер ряда для победы" },
	{ "init_error_ratio","Неверное соотношение параметров" },
	{ "init_error_lang","Неверный сохранённый номер языка" },
	{ "init_error_output","Неверный сохранённый номер настройки очистки экрана" },
	{ "init_default","Загрузка стандартных настроек" },
	{ "init_done","Настройки успешно загружены" },
	{ "game_second_name","Введите имя второго игрока (латиница)" },
	{ "game_showing","Вы начали матч против" },
	{ "game_showing_2","себя" },
	{ "game_win","Игрок" },
	{ "game_win_2","победил" },
	{ "game_draw","Ничья" },
	{ "game_enter","Введите номера столбца и строки" },
	{ "game_error_used","Эта ячейка уже занята" },
	};
	return lang;
}
namespace Color
{
	enum {
		BLACK = 0,
		DARKBLUE = FOREGROUND_BLUE,
		DARKGREEN = FOREGROUND_GREEN,
		DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
		DARKRED = FOREGROUND_RED,
		DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
		DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
		DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		GRAY = FOREGROUND_INTENSITY,
		BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
		MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
		YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	};
}
struct settings_list {                   //Данные о настройках
	string player_name;
	int field_width;
	int field_height;
	int row;
	int language;
	bool output;
	settings_list operator = (settings_list kek) {
		this->player_name = kek.player_name;
		this->field_width = kek.field_width;
		this->field_height = kek.field_height;
		this->row = kek.row;
		this->language = kek.language;
		this->output = kek.output;
		return (*this);
	}
};
settings_list current_settings;
//Функции
bool isdigitc(const char*text) {
	for (const char*str = text; *str; str++) { if (!(isdigit(*str)))return 0; }return 1;
}
bool sislat(const char *text) {
	const char *str = text;
	for (; *str; str++) {
		if (!(*str <= 255 && *str >= -1)) return false;
		if (!(isalpha(*str)||(isdigit(*str))))return false;
	}
	return true;
}// Const Char is Integer
bool nickname_check(string value) { if ((value.length() > 0) && (value.length() <= 100) && (sislat(value.c_str())))return true; else return false; }
bool number_check(string value, int min, int max) { if ((atoi(value.c_str()) >= min) && (atoi(value.c_str()) <= max) && (isdigitc(value.c_str())))return true; else return false; }
void check_language(int language, bool write) {
	SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
	if (language == 1) { setlocale(LC_ALL, "English"); lang = language_english(); if (write) cout << "Language changed to English." << endl; }
	else if (language == 2) { setlocale(LC_ALL, "Russian"); lang = language_russian(); if (write) cout << "Язык изменён на Русский." << endl; }
}
void game(settings_list settings) {  //Процесс игры
	string first_name = settings.player_name;
	int width = settings.field_width, height = settings.field_height, row = settings.row;
	int **field = new int *[height], player_switch = 2, w, h;
	string w_text, h_text, second_name, current_name;
	bool win = false;
	for (h = 1; h <= height; h++) { field[h - 1] = new int[width]; }
	for (h = 1; h <= height; h++) { for (w = 1; w <= width; w++) { field[h - 1][w - 1] = 0; } }
	SetConsoleTextAttribute(kek, (WORD)Color::WHITE);
	do { cout << lang["game_second_name"] << ": "; cin >> second_name; cin.ignore(numeric_limits<streamsize>::max(), '\n'); } while (!nickname_check(second_name));
	if (settings.output) system("cls");
	SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
	cout << lang["game_showing"] << " "; if (first_name == second_name) cout << lang["game_showing_2"]; else cout << second_name; cout << "." << endl;
	while (!win) {
		//Отрисовка поля
		SetConsoleTextAttribute(kek, (WORD)Color::DARKMAGENTA);
		cout << "#"; for (w = 1; w <= width; w++) { cout << "##"; }cout << endl;
		for (h = 1; h <= height; h++) {
			cout << "#";
			for (w = 1; w <= width; w++) {
				SetConsoleTextAttribute(kek, (WORD)Color::GREEN);
				switch (field[h - 1][w - 1]) {
				case 0:cout << " "; break;
				case 1:cout << "X"; break;
				case 2:cout << "O"; break;
				}
				SetConsoleTextAttribute(kek, (WORD)Color::DARKMAGENTA);
				cout << "#";
			}
			cout << endl << "#";
			for (w = 1; w <= width; w++) { cout << "##"; }
			cout << endl;
		}
		//Проверка поля
		for (h = 1; h <= height; h++) {
			for (w = 1; w <= (width - (row - 1)); w++) {
				int w2; bool running = true;
				for (w2 = 1; (w2 <= row) && (running); w2++) {
					if (field[h - 1][w2 + w - 2] != player_switch)running = false;
				}
				if (running) {
					SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
					cout << lang["game_win"] << " "; if (player_switch == 1)cout << first_name; else cout << second_name; cout << " " << lang["game_win_2"] << "." << endl;
					win = true;
				}
			}
		}
		for (w = 1; w <= width; w++) {
			for (h = 1; h <= (height - (row - 1)); h++) {
				int h2; bool running = true;
				for (h2 = 1; (h2 <= row) && (running); h2++) {
					if (field[h2 + h - 2][w - 1] != player_switch)running = false;
				}
				if (running) {
					SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
					cout << lang["game_win"] << " "; if (player_switch == 1)cout << first_name; else cout << second_name; cout << " " << lang["game_win_2"] << endl;
					win = true;
				}
			}
		}
		for (h = 1; h <= (height - (row - 1)); h++) {
			for (w = 1; w <= (width - (row - 1)); w++) {
				int h2, w2; bool running = true;
				for (h2 = 1, w2 = 1; (h2 <= row) && (w2 <= row) && (running); h2++, w2++) {
					if (field[h2 + h - 2][w2 + w - 2] != player_switch)running = false;
				}
				if (running) {
					SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
					cout << lang["game_win"] << " "; if (player_switch == 1)cout << first_name; else cout << second_name; cout << " " << lang["game_win_2"] << endl;
					win = true;
				}
			}
		}
		for (h = 1; h <= (height - (row - 1)); h++) {
			for (w = 1; w <= (width - (row - 1)); w++) {
				int h2, w2; bool running = true;
				for (h2 = 1, w2 = 1; (h2 <= row) && (w2 <= row) && (running); h2++, w2++) {
					if (field[h2 + h - 2][width - w - w2 + 1] != player_switch)running = false;
				}
				if (running) {
					SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
					cout << lang["game_win"] << " "; if (player_switch == 1)cout << first_name; else cout << second_name; cout << " " << lang["game_win_2"] << endl;
					win = true;
				}
			}
		}
		bool draw = true;
		for (h = 1; h <= height; h++)for (w = 1; w <= width; w++)if (field[h - 1][w - 1] == 0)draw = false;
		if (draw && !win) {
			SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
			cout << lang["game_draw"] << "!\n"; win = true;
		}
		if (win) continue;
		//Начало хода
		if (player_switch == 1) { player_switch = 2; current_name = second_name; }
		else { player_switch = 1; current_name = first_name; }
		w_text.clear(), h_text.clear();
		SetConsoleTextAttribute(kek, (WORD)Color::WHITE);
		//Информация о ходе
		if (settings.language == 1) { cout << current_name << "'"; if (current_name[current_name.length() - 1] != 's' && current_name[current_name.length() - 1] != 'S') { cout << "s"; }cout << " turn"; }
		else if (settings.language == 2) { cout << "Ход игрока " << current_name; }
		cout << ". ("; if (player_switch == 1)cout << "X"; else cout << "O"; cout << ") ";
		//Ввод данных хода
		while (!((w_text.length() <= 2) && (h_text.length() <= 2) && (atoi(w_text.c_str()) <= width) && (atoi(h_text.c_str()) <= height) && (atoi(w_text.c_str()) != 0) && (atoi(h_text.c_str()) != 0))) {
		back:
			cout << lang["game_enter"] << ": "; cin >> w_text >> h_text; cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (field[atoi(h_text.c_str()) - 1][atoi(w_text.c_str()) - 1] != 0) {
			cout << lang["game_error_used"] << ". ";
			goto back;
		}
		field[atoi(h_text.c_str()) - 1][atoi(w_text.c_str()) - 1] = player_switch;
		if (settings.output) system("cls");
	}
	//Очистка данных матча
	for (h = 1; h <= height; h++) { delete[]field[h - 1]; }w_text.clear(); h_text.clear();
	if (settings.output) { _getch(); system("cls"); }
}
void set_default_settings() {            //Установка базовых настроек
	current_settings.player_name = "Player";
	current_settings.field_width = 3;
	current_settings.field_height = 3;
	current_settings.row = 3;
	current_settings.language = 1;
	lang = language_english();
	current_settings.output = false;
}
void init_settings() {					//Инициализация сохранённых настроек
	SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
	if (lang.empty()) lang = language_english();
	cout << lang["init_start"] << ":\n";
	ifstream fin("settings.txt");
	if (!fin.is_open()) { cout << lang["init_empty"] << ". " << lang["init_default"] << "...\n"; set_default_settings(); return; }
	string text;
	getline(fin, text);
	if (!nickname_check(text)) { cout << lang["init_error_name"] << ". " << lang["init_default"] << "...\n"; set_default_settings(); return;}
	else current_settings.player_name = text;
	getline(fin, text);
	if (!number_check(text,3,39)) { cout << lang["init_error_width"] << ". " << lang["init_default"] << "...\n"; set_default_settings(); return; }
	else current_settings.field_width = atoi(text.c_str());
	getline(fin, text);
	if (!number_check(text,3,39)) { cout << lang["init_error_height"] << ". " << lang["init_default"] << "...\n"; set_default_settings(); return; }
	else current_settings.field_height = atoi(text.c_str());
	getline(fin, text);
	if (!number_check(text,3,10)) { cout << lang["init_error_row"] << ". " << lang["init_default"] << "...\n"; set_default_settings(); return; }
	else current_settings.row = atoi(text.c_str());
	if ((current_settings.field_width < current_settings.row) && (current_settings.field_height < current_settings.row)) {
		cout << lang["init_error_ratio"] << ". " << lang["init_default"] << "...\n"; set_default_settings(); return; }
	getline(fin, text);
	if (!number_check(text,1,2)) { cout << lang["init_error_lang"] << ". " << lang["init_default"] << "...\n"; set_default_settings(); return; }
	else current_settings.language = atoi(text.c_str());
	getline(fin, text);
	if (!number_check(text,0,1)) { cout << lang["init_error_output"] << ". " << lang["init_default"] << "...\n"; set_default_settings(); return; }
	else if (atoi(text.c_str()) == 0) current_settings.output = false; else current_settings.output = true;
	if (current_settings.language == 1) lang = language_english();
	else if (current_settings.language == 2) lang = language_russian();
	cout << lang["init_done"] << ".\n"; fin.close(); return;
}
void save_settings(settings_list settings) {					//Сохранение изменённых настроек
	ofstream fout("settings.txt");
	fout << settings.player_name
		<< endl << settings.field_width
		<< endl << settings.field_height
		<< endl << settings.row
		<< endl << settings.language
		<< endl << settings.output;
	SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
	cout << lang["settings_saved"] << ".\n";
}
settings_list settings() {               //Изменение настроек
	settings_list changed_settings;
	changed_settings.player_name = current_settings.player_name;
	changed_settings.field_width = current_settings.field_width;
	changed_settings.field_height = current_settings.field_height;
	changed_settings.row = current_settings.row;
	changed_settings.language = current_settings.language;
	changed_settings.output = current_settings.output;
	while (true) {
		SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
		cout << endl << "-----" << lang["settings"] << ":" << endl;
		SetConsoleTextAttribute(kek, (WORD)Color::CYAN);
		string output_info; if (changed_settings.output) output_info = lang["output_on_info"]; else output_info = lang["output_off_info"];
		cout << lang["current_settings"] << ":" << endl
			<< lang["name_info"] << ": " << changed_settings.player_name << endl
			<< lang["width_info"] << ": " << changed_settings.field_width << endl
			<< lang["height_info"] << ": " << changed_settings.field_height << endl
			<< lang["row_info"] << ": " << changed_settings.row << endl
			<< lang["lang_info"] << endl
			<< lang["output_info"] << ": " << output_info << endl;
		SetConsoleTextAttribute(kek, (WORD)Color::GREEN);
		string output_change; if (changed_settings.output) output_change = lang["output_off"]; else output_change = lang["output_on"];
		cout << "-----1." << lang["name_change"] << endl
			<< "-----2." << lang["width_change"] << endl
			<< "-----3." << lang["height_change"] << endl
			<< "-----4." << lang["row_change"] << endl
			<< "-----5." << lang["lang_change"] << endl
			<< "-----6." << output_change << endl
			<< "-----7." << lang["save"] << endl
			<< "-----8." << lang["cancel"] << endl;
		string settings_choose;
		SetConsoleTextAttribute(kek, (WORD)Color::WHITE);
		while (!number_check(settings_choose, 1, 8)) {
			cout << lang["choose_one"] << ": ";
			cin >> settings_choose; cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (changed_settings.output) system("cls");
		if (atoi(settings_choose.c_str()) == 1) {
			string value;
			do {
				cout << lang["name_enter"] << ": "; cin >> value; cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} while (!nickname_check(value));
			if (changed_settings.output) system("cls");
			changed_settings.player_name = value;
		}
		if (atoi(settings_choose.c_str()) == 2) {
			string value;
			do {
				rewidth:cout << lang["width_enter"] << ": "; cin >> value; cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if ((atoi(value.c_str())<changed_settings.row) && (changed_settings.field_height<changed_settings.row)) {
					cout << lang["width_error"] << "." << endl;
					if ((atoi(value.c_str()) >= 3) && (atoi(value.c_str()) <= 10))changed_settings.row = atoi(value.c_str());
					else if (atoi(value.c_str())<3)changed_settings.row = 3;
					else if (atoi(value.c_str())>10)changed_settings.row = 10;
					SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
					cout << lang["row_changed"] << " " << changed_settings.row << ".\n";
					SetConsoleTextAttribute(kek, (WORD)Color::WHITE);
					if (changed_settings.output) _getch();
					goto rewidth;
				}
			} while (!number_check(value, 3, 39));
			if (changed_settings.output) system("cls");
			changed_settings.field_width = atoi(value.c_str());
		}
		if (atoi(settings_choose.c_str()) == 3) {
			string value;
			do {
				reheigth:cout << lang["height_enter"] << ": "; cin >> value; cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if ((atoi(value.c_str())<changed_settings.row) && (changed_settings.field_width<changed_settings.row)) {
					cout << lang["height_error"] << "." << endl;
					if ((atoi(value.c_str()) >= 3) && (atoi(value.c_str()) <= 10))changed_settings.row = atoi(value.c_str());
					else if (atoi(value.c_str())<3)changed_settings.row = 3;
					else if (atoi(value.c_str())>10)changed_settings.row = 10;
					SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
					cout << lang["row_changed"] << " " << changed_settings.row << ".\n";
					SetConsoleTextAttribute(kek, (WORD)Color::WHITE);
					if (changed_settings.output) _getch();
					goto reheigth;
				}
			} while (!number_check(value, 3, 39));
			if (changed_settings.output) system("cls");
			changed_settings.field_height = atoi(value.c_str());
		}
		if (atoi(settings_choose.c_str()) == 4) {
			string value;
			do {
				renumber:cout << lang["row_enter"] << ": "; cin >> value; cin.ignore(numeric_limits<streamsize>::max(), '\n'); if (changed_settings.output) system("cls");
				if ((atoi(value.c_str())>changed_settings.field_width) && (atoi(value.c_str())>changed_settings.field_height)) {
					cout << lang["row_error"] << "." << endl;
					if (changed_settings.output) _getch();
					goto renumber;
				}
			} while (!number_check(value, 3, 10));
			if (changed_settings.output) system("cls");
			changed_settings.row = atoi(value.c_str());
		}
		if (atoi(settings_choose.c_str()) == 5) {
			SetConsoleTextAttribute(kek, (WORD)Color::GREEN);
			setlocale(LC_ALL, "English"); cout << "-----1." << "English\n";
			setlocale(LC_ALL, "Russian"); cout << "-----2." << "Русский\n";
			SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
			check_language(current_settings.language, false);
			string value;
			do {
				SetConsoleTextAttribute(kek, (WORD)Color::WHITE);
				cout << lang["lang_enter"] << ": "; cin >> value; cin.ignore(numeric_limits<streamsize>::max(), '\n');
				SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
				check_language(atoi(value.c_str()), true);
			} while (!number_check(value, 1, 2));
			if (changed_settings.output) system("cls");
			changed_settings.language = atoi(value.c_str());
		}
		if (atoi(settings_choose.c_str()) == 6) {
			if (changed_settings.output) changed_settings.output = false; else { changed_settings.output = true; system("cls"); }
		}
		if (atoi(settings_choose.c_str()) == 7) { save_settings(changed_settings); return changed_settings; }
		if (atoi(settings_choose.c_str()) == 8) {
			SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
			check_language(current_settings.language, false);
			return current_settings;
		}
	}
}
int main()                              //Главное меню
{
	init_settings();
	while (true) {
		cout << endl;
		char *menu_choose_text = new char[2]; int menu_choose;
		SetConsoleTextAttribute(kek, (WORD)Color::YELLOW);
		cout << "-----[Tic-Tac-Toe Advanced]-----" << endl;
		SetConsoleTextAttribute(kek, (WORD)Color::GREEN);
		cout << "-----1." << lang["start_game"] << endl
			<< "-----2." << lang["settings"] << endl
			<< "-----3." << lang["exit"] << endl;
		SetConsoleTextAttribute(kek, (WORD)Color::WHITE);
		while (!((atoi(menu_choose_text) <= 3) && (atoi(menu_choose_text) >= 1))) {
			cout << lang["choose_one"] << ": ";
			cin >> menu_choose_text; cin.ignore(numeric_limits<streamsize>::max(), '\n'); if (current_settings.output) system("cls");
		}
		if (current_settings.output) system("cls");
		menu_choose = atoi(menu_choose_text);
		delete menu_choose_text;
		if (menu_choose == 1) { game(current_settings); };
		if (menu_choose == 2) { current_settings = settings(); }
		if (menu_choose == 3) { return(0); }
	}
}