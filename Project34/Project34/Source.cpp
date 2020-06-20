#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(int text, int background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y)
{
	COORD c = { X, Y };
	SetConsoleCursorPosition(hStdOut, c);
}

class poin
{
	int X, Y;
public:
	poin(int x, int y) { X = x; Y = y; }
	int _X() { return X; }
	int _Y() { return Y; }
	poin& X_i() { X++; return *this; }
	poin& X_d() { X--; return *this; }
	poin& Y_i() { Y++; return *this; }
	poin& Y_d() { Y--; return *this; }

};
class rectange
{
	poin p;
	int h;
	int w;
	bool _top;
public:
	rectange() :p(1, 1) { h = 3, w = 3, _top = false; };
	rectange(int _x, int _y, int _h = 3, int _w = 3) : p(_x, _y) { h = _h; w = _w; _top = false; }
	void clear();
	void print();
	void resize(int);
	void top() { _top = !_top; }
	void move(int i_input)
	{
		if (_top)
		{
			clear();
			switch (i_input)
			{
			case 72://вверх
				p.Y_d(); break;
			case 80://вниз
				p.Y_i(); break;
			case 75://влево
				p.X_d(); break;
			case 77://вправо
				p.X_i();
			}
		}
	}
};
void rectange::print()
{
	if (_top)
		SetColor(0, 11);
	for (int i = 0; i < h; i++)
	{
		GotoXY(p._X(), p._Y() + i);
		for (int j = 0; j < w; j++)
			cout << "*";
		cout << endl;
	}
	SetColor(7, 0);
}
void rectange::resize(int) {}
void rectange::clear()
{
	for (int i = 0; i < h; i++)
	{
		GotoXY(p._X(), p._Y() + i);
		for (int j = 0; j < w; j++)
			cout << " ";
		cout << endl;
	}
}
int main()
{
	rectange r(5, 8), t(12, 6); int vvod;
	r.top();
	while (1)
	{
		vvod = _getch();
		if (vvod == 224)
		{
			vvod = _getch();
			t.move(vvod);
			r.move(vvod);
		}
		else if (vvod == 13)
		{
			t.top();
			r.top();
		}
		t.print();
		r.print();
	}
	system("pause");
	return 0;

}