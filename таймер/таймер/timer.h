#pragma once
#ifndef TIMER_H
#define TIMER_H
#include<iostream>
#include<iomanip>
using namespace std;
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
class timer {

	int begin;
	int end;
	int seconds;
public:
	timer(int date_begin, int date_end) {
		begin = date_begin;
		end = date_end;
		seconds = begin;

	}
	timer& operator ++(int) {
		if (seconds < end)
			seconds++;
		return*this;
	}
	void message() {
		gotoxy(0, 0);
		cout << seconds;
	}
};
#endif
