#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Rational {
	int numerator;
	int denominator;
	double rational;

public:
	int getNumerator();
	void setNumerator(int);

	int getDenominator();
	void setDenominator(int);

	double getRational();
	void setRational(double);

	void converted();
	void reduce();

	void input();
	void output() const;

	Rational();
	Rational(int, int);
};

// Constructor
Rational::Rational()
{
	numerator = 1;
	denominator = 1;
	rational = 0.0;
}

Rational::Rational(int n1, int n2 = 1)
{
	numerator = n1;
	setDenominator(n2);
	denominator = getDenominator();
}

// Getter - Setter
int Rational::getNumerator()
{
	return numerator;
}
void Rational::setNumerator(int num)
{
	numerator = num;
}

int Rational::getDenominator()
{
	return denominator;
}

void Rational::setDenominator(int num)
{
	num == 0 ? (denominator = 1) : (denominator = num);
}

double Rational::getRational()
{
	return rational;
}

void Rational::setRational(double num)
{
	rational = num;
}

void Rational::converted()
{
	if (denominator < 0) {
		if (numerator < 0 && denominator < 0) {
			numerator = abs(numerator);
			denominator = abs(denominator);
		}
		else {
			numerator *= (-1);
		}
	}
}

void Rational::reduce()
{
	int result = min(numerator, denominator);
	while (result > 0) {
		if (numerator % result == 0 && denominator % result == 0) {
			break;
		}
		result--;
	}
	numerator /= result;
	denominator /= result;
	
	rational = result;
}

// Input - Output

void Rational::input()
{
	cout << "Enter a Numerator: ";
	cin >> numerator;

	cout << "Enter a Denominator: ";
	cin >> denominator;

	while (denominator == 0) {
		cout << "\n--------------------------------------------------\n"
			<< "Denominator can't = 0. Enter a different number!!"
			<< "\n--------------------------------------------------\n";
		cout << "Enter a Denominator: ";
		cin >> denominator;
	}
}

void Rational::output() const
{
	cout << "\nRational: " << numerator << " / " << denominator << endl;
	
}



int main() {

	Rational rationalA, rationalB(6), rationalC(-6,-8), rationalD(9,-6);

	cout << "Rational A\n";
	rationalA.input();
	rationalA.converted();
	rationalA.reduce();
	rationalA.output();

	cout << "\n----------------------\n";
	cout << "Rational B";
	rationalB.converted();
	rationalB.reduce();
	rationalB.output();

	cout << "\n----------------------\n";
	cout << "Rational C";
	rationalC.converted();
	rationalC.reduce();
	rationalC.output();

	cout << "\n----------------------\n";
	cout << "Rational D";
	rationalD.converted();
	rationalD.reduce();
	rationalD.output();

	return 0;
}
