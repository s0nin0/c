#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;
void gotoxy(short x, short y) // хождения по координатам - gotoxy(0, 0);
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
void SetColor(int text, int background = 0)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
template <class T>
class Vector
{
	T*p;
	int size;
public:
	Vector(int = 0, T* = nullptr);
	Vector(const Vector&);
	~Vector();
	int operator[](int);
	int Size();
	T* Get();
	void Set();
	Vector add(T);
	Vector del(T);
	T Max()const;
	T Min()const;
	Vector replace(T, T);
	Vector Sort();
	Vector Sort(int);
	template <class T>
	friend ostream & operator <<(ostream&, const Vector<T> &);
	template <class T>
	friend istream & operator >>(istream&, Vector<T> &);
	Vector operator + (const Vector<T>&)const;
	Vector operator - (const Vector<T>&);
	Vector operator * (const Vector<T> &);
	Vector operator / (const Vector<T> &);
};
template <class T>
 T Vector<T>::Max()const
{
	T Max = 1 << 31;
	for (int i = 0; i < size; i++)
		if (p[i] > Max)
			Max = p[i];
	return Max;
}
 template <class T>
T Vector<T>::Min()const
{
	T Min = ~(1 << 31);
	for (int i = 0; i < size; i++)
		if (p[i] < Min)
			Min = p[i];
	return Min;
}
template <class T>
Vector<T> Vector<T>:: operator + (const Vector<T>&v)const
{
	Vector a;
	a.size = this->size + v.size;
	a.p = new int[a.size];
	for (int i = 0; i < size; i++)
		a.p[i] = p[i];
	for (int i = size, j = 0; i < a.size; i++, j++)
		a.p[i] = v.p[j];
	return a;
}
template <class T>
Vector<T> Vector<T>:: operator - (const Vector<T>&v)
{
	Vector a = *this;
	for (int i = 0; i < v.size; i++)
		for (int j = 0; j < a.size; j++)
			if (a.p[j] == v.p[i])
			{
				a.del(j);
				--j;
			}
	return a;
}
template <class T>
Vector<T> Vector<T> :: operator * (const Vector<T> &v)
{
	Vector c;
	int Min = this->Min() < v.Min() ? this->Min() : v.Min();
	int Max = this->Max() > v.Max() ? this->Max() : v.Max();
	int a, b;
	for (int j = Min; j <= Max; j++)
	{
		a = 0; b = 0;
		for (int i = 0; i < size; i++)
			if (p[i] == j)
				a++;
		for (int i = 0; i < v.size; i++)
			if (v.p[i] == j)
				b++;
		if (a&&b)
			c.add(j);
	}
	return c;
}
template <class T>
Vector<T> Vector<T> :: operator / (const Vector<T> &v)
{
	Vector c;
	int Min = this->Min() < v.Min() ? this->Min() : v.Min();
	int Max = this->Max() > v.Max() ? this->Max() : v.Max();
	int a, b;
	for (int j = Min; j < Max; j++)
	{
		a = 0; b = 0;
		for (int i = 0; i < size; i++)
			if (p[i] == j)
				a++;
		for (int i = 0; i < v.size; i++)
			if (v.p[i] == j)
				b++;
		if (!a&&b || a && !b)
			c.add(j);
	}
	return c;
}
template <class T>
int Vector<T>::Size() { return size; }
template <class T>
Vector<T> Vector<T>::add(T val) // добавляем элемент увеличивая размер массива на 1
{
	int *temp = new int[++size];
	for (int i = 0; i < size; i++)
		temp[i] = i < size - 1 ? p[i] : val;
	delete[]p;
	p = temp;
	return *this;
}
template <class T>
Vector<T> Vector<T>::del(T ind)
{
	int *temp = new int[--size];
	for (int i = 0; i < size; i++)
		temp[i] = i < ind ? p[i] : p[i + 1];
	delete[]p;
	p = temp;
	return *this;
}
template <class T>
Vector<T>::Vector<T>(int s, T*n)
{
	size = s;
	p = new int[s];
	for (int i = 0; i < s; i++)
		p[i] = n ? n[i] : 0;
}
template <class T>
Vector<T>::Vector<T>(const Vector<T>&v)
{
	p = new int[v.size];
	for (int i = 0; i < v.size; i++)
		p[i] = v.p[i];
	size = v.size;
}
template <class T>
Vector<T>::~Vector<T>() { delete[]p; }
template <class T>
int Vector<T>::operator[](int i) { return (i && i < size ? p[i] : 0); }
template <class T>
T* Vector<T>::Get() { return p; }
template <class T>
void Vector<T>::Set()
{
	int s;
	cout << "Set size Vector (" << size << "): ";
	cin >> s;
	int* temp = new int[s];
	for (int i = 0; i < s; i++)
	{
		cout << (i < size ? p[i] : 0) << " -> ";
		cin >> temp[i];
	}
	delete[]p;
	p = temp;
	size = s;
}
template <class T>
ostream & operator << (ostream& os, const Vector<T>& v) //os
{
	for (int i = 0; i < v.size; i++)
		cout << " " << v.p[i];
	return os;
}
template <class T>
istream & operator >>(istream&is, Vector<T> &v)
{
	int l = 0, temp = 1, t;
	system("cls");
	while (temp != 27)
	{
		gotoxy(0, 0);
		for (int i = 0; i <= v.size; i++)
		{
			if (i == l)
				SetColor(0, 14);
			if (i < v.size)
				cout << setw(5) << v.p[i];
			else
				cout << setw(5) << ' ';
			SetColor(7, 0);
		}
		temp = _getch();
		if (temp == 224)
		{
			temp = _getch();
			if (temp == 75 && l)
				l--;
			else if (temp == 77 && l != v.size)
				l++;
			else if (temp == 82)
			{
				gotoxy(l * 5, 0);
				if (l == v.size)
				{
					cin >> t;
					v.add(t);
				}
				else
					cin >> v.p[l];
			}
		}
	}
	system("cls");
	return is;
}
template <class T>
Vector<T> Vector<T>::replace(T a, T b) // заменяет числа с а на b
{
	for (int i = 0; i < size; i++)
	{
		if (p[i] == a)
		{
			p[i] = b;
		}
	}
	return *this;
}
template <class T>
Vector<T> Vector<T>::Sort() // сортировка по возрастанию
{
	int j;
	for (int i = 1; i < size; i++)
	{
		j = i;
		while (j > 0 && p[j] < p[j - 1])
		{
			swap(p[j], p[j - 1]);
			j--;
		}
	}
	return *this;
}
template <class T>
Vector<T> Vector<T>::Sort(int) //сортировка по убыванию
{
	int i, j;
	for (i = 1; i < size; i++)
	{
		j = i;
		while (j > 0 && p[j] > p[j - 1])
		{
			swap(p[j], p[j - 1]);
			j--;
		}
	}
	return *this;
}
void main()
{
	setlocale(0, "");
	srand(time(NULL));
	const int s = 10;
	int ar1[s], ar2[s];
	for (int i = 0; i < s; i++)
		ar1[i] = 1 + rand() % 15;
	for (int i = 0; i < s; i++)
		ar2[i] = 1 + rand() % 15;
	Vector<int> a1(s, ar1), a2(s, ar2);
	cout << a1 << endl;
	cout << a2 << endl;
	cout << "a1*a2:\n";
	cout << (a1*a2).Sort() << endl;
	cout << "a1/a2:\n";
	cout << (a1 / a2).Sort(0) << endl;
	cout << "a1+a2:\n";
	cout << (a1 + a2).Sort() << endl;
	cout << "a1-a2:\n";
	cout << (a1 - a2).Sort(0) << endl;
	cout << "a2-a1:\n";
	cout << (a2 - a1).Sort() << endl;
	system("pause");
}
