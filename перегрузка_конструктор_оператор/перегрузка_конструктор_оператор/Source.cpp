#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include "Header.h"
using namespace std;

int main() {
	double rez4;
	vector aa, bb, rez1, rez2, rez3;
	cout << "Введите координаты вестора а\n";
	aa.put();
	cout << "Введите координаты вестора b\n";
	bb.put();
	aa.show();
	cout << endl;
	bb.show();
	cout << endl;
	rez1 = aa + bb;
	cout << "Сумма:\n";
	rez1.show();
	cout << endl;
	cout << "Вычитание:\n";

	rez2 = aa - bb;
	rez2.show();
	cout << endl;
	system("pause");
}