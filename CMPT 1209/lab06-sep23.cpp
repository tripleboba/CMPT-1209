#include <iostream>
#include <string>
using namespace std;

class Rational
{
private:
	int numer;
	int denom;
public:
	int getNumer() const;
	int getDenom() const;
	void setNumer(int);
	void setDenom(int);
	void input();
	void output(bool) const;
	Rational();
	Rational(int, int = 1);
	void reduce();
};
void Rational::reduce()
{
	int x = abs(numer);
	int y = abs(denom);
	// find minimum of x and y
	int min = x;
	if (y < x)
		min = y;
	// finding a common factor greater than 1
	int gcf = 1;
	for (int i = 2; i <= min; i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			gcf = i;
		}
	}
	numer = numer / gcf;
	denom = denom / gcf;
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
}
Rational::Rational()
{
	numer = 0;
	denom = 1;
}
Rational::Rational(int x, int y)
{
	numer = x;
	if (y != 0)
		denom = y;
	else
		denom = 1;
	reduce();
}
int Rational::getNumer() const
{
	return numer;
}
int Rational::getDenom() const
{
	return denom;
}
void Rational::setNumer(int x)
{
	numer = x;
	reduce();
}
void Rational::setDenom(int x)
{
	denom = x;
	if (denom == 0)
		denom = 1;
	reduce();
}
void Rational::input()
{
	cout << "Numerator? ";
	cin >> numer;
	cout << "Denominator? ";
	cin >> denom;
	while (denom == 0)
	{
		cout << "Denominator can't be zero!\n";
		cout << "Denominator? ";
		cin >> denom;
	}
	reduce();
}
void Rational::output(bool isBoolReturn = false) const
{
	if (isBoolReturn) {
		cout << (numer ? "true" : "false");
	}
	else {

		if (denom != 1)
			cout << numer << "/" << denom << endl;
		else
			cout << numer << endl;
	}
}

// ------------- OPERATOR OVERLOADING + - * / -------------
// not member of a class method to overload -> no Rational::
// usage pros: defing after the class
Rational operator+(Rational a, Rational b) {

	// Purpose is to do a/b + c/d for Rational a and Rational b
	// a/b + c/d = (ad+bc)/bd
	Rational c;

	//a.numer; // error due to numer is a PRIVATE var of class Rational (line 6) -> need to call get/setNumer();

	c.setNumer((a.getNumer() * b.getDenom()) + (a.getDenom() * b.getNumer()));
	c.setDenom(a.getDenom() * b.getDenom());

	return c;
}

Rational operator-(const Rational& a, const Rational& b) { // call by value func -> pros: values of b and c in main() aren't manipulated
	// a.setDenom(2); // throw error as using const in param -> original value is being manipulated
	// need to go with var() define with const -> int getNumer() const;
	int n = (a.getNumer() * b.getDenom()) - (a.getDenom() * b.getNumer());
	int d = a.getDenom() * b.getDenom();
	return (n == 0 ? 0 : Rational(n, d)); // otherwise display is 0/16
}

Rational operator*(Rational a, Rational b) {
	int n = a.getNumer() * b.getNumer();
	int d = a.getDenom() * b.getDenom();
	return Rational(n, d);
}

Rational operator/(Rational a, Rational b) {
	int n = a.getNumer() * b.getDenom();
	int d = a.getDenom() * b.getNumer();
	return Rational(n, d);
}

// ------------- OPERATOR OVERLOADING > < >= <= -------------
// a/b < c/d === ad < cb
bool operator<(const Rational& a, const Rational& b) {
	int num1 = a.getNumer() * b.getDenom();
	int num2 = a.getDenom() * b.getNumer();
	return num1 < num2;
}
bool operator<=(const Rational& a, const Rational& b) {
	int num1 = a.getNumer() * b.getDenom();
	int num2 = a.getDenom() * b.getNumer();
	return num1 <= num2;
}
bool operator>(const Rational& a, const Rational& b) {
	int num1 = a.getNumer() * b.getDenom();
	int num2 = a.getDenom() * b.getNumer();
	return num1 > num2;
}
bool operator>=(const Rational& a, const Rational& b) {
	int num1 = a.getNumer() * b.getDenom();
	int num2 = a.getDenom() * b.getNumer();
	return num1 >= num2;
}

// ------------- OPERATOR OVERLOADING == != -------------
bool operator==(const Rational& a, const Rational& b) {
	int num1 = a.getNumer() * b.getDenom();
	int num2 = a.getDenom() * b.getNumer();
	return num1 == num2;
}
bool operator!=(const Rational& a, const Rational& b) {
	return !operator==(a, b);
}

// ------------- OPERATOR OVERLOADING += -= *= /= -------------
Rational operator+=(Rational& a, const Rational& b) { // !!!!!
	// if using Rational a: the original value is not manipulated -> return is wrong as the calculation is the copy of the original value
	a = a + b;
	return a;
}
Rational operator-=(Rational& a, const Rational& b) {
	a = a - b;
	return a;
}
Rational operator*=(Rational& a, const Rational& b) {
	a = a * b;
	return a;
}
Rational operator/=(Rational& a, const Rational& b) {
	a = a / b;
	return a;
}

// ------------- OPERATOR OVERLOADING ++ -- -------------
// postfix
// y = a++; -> y = a; -> a++
// prefix
// y = ++a; -> ++a; -> y = a

// void operator++(Rational& a) {
//	a.setNumer(a.getNumer() + a.getDenom());
// }
// this will make ++a; in main() work while a++ won't be overloaded by this ()

Rational operator++(Rational& a) {
	// for prefix implementation: b = ++a;
	a.setNumer(a.getNumer() + a.getDenom());
	return a;
}

Rational operator++(Rational& a, int) {
	// for postfix implementation: b = a++;
	// Rational a, Rational b(1/4)
	// bug without _temp in main() a = b++; a.output() b.output()
	// a -> 5/4 and b -> 5/4 while correct is a -> 1/4 as postfix rule that a = b -> a.output -> a + b
	Rational _temp = a;
	a.setNumer(a.getNumer() + a.getDenom());
	return a;
}


int main()
{
	Rational a, b(1, 2), c(1, 2), d(9, -6), r;
	//a.output();

	cout << "\nRational b:";
	b.output();
	cout << "\nRational c:";
	c.output();

	//d.output();

	cout << "\n---------Operator Overloading------------\n";
	// Operator Overload + - * /
	// rationalA = rationalB + rationalC
	r = b + c;
	cout << "Operator +: ";
	r.output();

	r = b - c;  // call by value func -> pros: values of b and c aren't manipulated
	// if error -> main() is the only location to be checked on value manipulated
	// cons: more memories are used -> not efficient
	cout << "\nOperator -: ";
	r.output();
	r = b * c;
	cout << "\nOperator *: ";
	r.output();
	r = b / c;
	cout << "\nOperator /: ";
	r.output();
	// call by references -> pros: efficient | cons: error occurs -> need to check the whole program

	// Operator Overload > < >= <=
	cout << "\nOperator <: ";
	r = b < c;
	r.output(true);
	cout << "\nOperator <=: ";
	r = b <= c;
	r.output(true);
	cout << "\nOperator >: ";
	r = b > c;
	r.output(true);
	cout << "\nOperator >=: ";
	r = b >= c;
	r.output(true);

	// Operator Overload == !=
	cout << "\n----Operator Overload == != ----\n";
	cout << "\nOperator ==: ";
	r = b == c;
	r.output(true);
	cout << "\nOperator !=: ";
	r = b != c;
	r.output(true);

	// Operator Overload += -= *= !=
	cout << "\n----Operator Overload += -= *= != ----\n";
	cout << "\nOperator +=: ";
	r = b += c;
	r.output();
	cout << "\nOperator -=: ";
	r = b -= c;
	r.output();
	cout << "\nOperator *=: ";
	r = b *= c;
	r.output();
	cout << "\nOperator /=: ";
	r = b /= c;
	r.output();


	return 0;
}