#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>
#include "Header.h"
using namespace std;

class vector {
private:
	float a;
	float b;
	float c;
public:
	vector() {}
	vector(float aa, float bb, float cc) {
		a = aa;
		b = bb;
		c = cc;
	}
	void put() {
		cin >> a;
		cin >> b;
		cin >> c;

	}
	void show() {
		cout << a;
		cout << b;
		cout << c;
	}
	vector operator + (vector a1);
	vector operator - (vector a1);
};
vector vector:: operator + (vector a1) {
	vector temp;
	temp.a = a + a1.a;
	temp.b = b + a1.b;
	temp.c = c + a1.c;
	return temp;
}
vector vector:: operator - (vector a1) {
	vector temp;
	temp.a = a - a1.a;
	temp.b = b - a1.b;
	temp.c = c - a1.c;
	return temp;
}
#endif