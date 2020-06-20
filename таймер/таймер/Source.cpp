#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include "timer.h"
using namespace std;

void main()
{

	setlocale(LC_ALL, "");
	srand(time(0));
	timer objtimer(30, 1000);
	while (1) {
		objtimer++.message();
		if (_kbhit()) break;
		Sleep(100);
			}

	system("pause");
}