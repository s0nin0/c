#include <iostream>
using namespace std;

class Vector {
public:
	int *ar;
	int a;
	Vector(){}
	Vector(const int b, int *arr){
		a = b;
		ar = new int[b];
		for (int i = 0; i < a; i++) {
			ar[i] = arr[i];
		}
		
	}
	Vector(const Vector&m) {
		ar = new int[m.a];
		for (int i = 0; i < m.a; i++) {
			ar[i] = m.ar[i];
		}
		a = m.a;
	}
	Vector add(int n) {
		int *d = new int[++a];
		for (int i = 0; i < a-1; i++) {
			d[i] = ar[i];
		}
		d[a - 1] = n;
		delete[] ar;
		ar = d;
		return *this;
	}
	Vector del(int n) {
		int *d = new int[--a];
		for (int i = 0; i < a; i++) {
			if (i < n) d[i] = ar[i];
			else d[i] = ar[i + 1];
		}
		delete[] ar;
		ar = d;
		return *this;

	}
	~Vector() {
		delete[] ar;
	}
	int max()const {
		int Max = ar[0];
		for (int i = 0; i < a; i++) {
			if (ar[i] > Max) Max = ar[i];
		}
		return Max;

	}
	int min() const{
		int Min = ar[0];
		for (int i = 0; i < a; i++) {
			if (ar[i] < Min) Min = ar[i];
		}
		return Min;
	}
	
	
	Vector operator+(const Vector &v1);
	Vector operator*(const Vector &v1);
	Vector operator/(const Vector &v1);
	Vector operator-(const Vector &v1);
};
Vector Vector::operator+(const Vector &v1)
{
	Vector c;
	c.a = this->a + v1.a;
	c.ar = new int[c.a];
	for (int i = 0; i < v1.a; i++) {
		c.ar[i] = ar[i];
	}
	for (int i = a, j = 0; i < c.a; i++, j++) {
		c.ar[i] = v1.ar[j];
	}
	return c;
}
Vector Vector::operator*(const Vector &v1)
{
	Vector z;
	int mini = this->min();
	int maxi = this->max();
	for (int i = mini; i <= maxi; i++)
	{
		int k = 0;
		int b = 0;
		for (int y = 0; y < a; y++)
			if (ar[y] == i) k++;
		for (int j = 0; j < v1.a; j++)
			if (v1.ar[j] == i) b++;
		if (k&&b) z.add(i);
	
	}
	return z;
}
Vector Vector::operator/(const Vector&v1) {
	Vector z;
	int mini = this->min() < v1.min() ? this->min() : v1.min();
	int maxi = this->max() > v1.max() ? this->max() : v1.max();
	for (int i = mini; i <= maxi; i++)
	{
		int k = 0;
		int b = 0;
		for (int y = 0; y < a; y++)
			if (ar[y] == i) k++;
		for (int j = 0; j < v1.a; j++)
			if (v1.ar[j] == i) b++;
		if (k>0&&b==0||b>0&&k==0) z.add(i);

	}
	return z;
}
Vector Vector::operator-(const Vector&v1) {
	Vector z= *this;
	for (int i = 0; i < v1.a; i++)
		for (int y = 0; y < z.a; y++)
			if (z.ar[y] == v1.ar[i]) {
				z.del(y);
				--y;
			}
	return z;
}
std::ostream& operator<< (std::ostream &out, const  Vector &point)
{
	// Поскольку operator<< является другом класса Point, то мы имеем прямой доступ к членам Point
	for (int i = 0; i < point.a; i++) {
	out << point.ar[i]<< "    ";
	}
	cout << endl;
	return out;
}
int main()
{
	setlocale(LC_ALL, "");
	const int s = 10;
	int arr1[s], arr2[s];
	for (int i = 0; i < s; i++)
		arr1[i] = 1 + rand() % 15;
	for (int i = 0; i < s; i++)
		arr2[i] = 1 + rand() % 15;
	Vector a1(s, arr1), a2(s, arr2);
	cout << a1 << endl;
	cout << a2 << endl;
	cout << (a1*a2) << endl;
	cout << (a1 / a2) << endl;
	cout << (a1 + a2) << endl;
	cout << (a1 - a2) << endl;
	cout << endl;
	system("pause");
}