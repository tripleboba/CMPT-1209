//#include <iostream>
//#include <string>
//using namespace std;
//
//class Laptop {
//	string manufacturer;
//	string processor;
//	double screenSize;
//	string color;
//	bool isNew;
//
//public:
//	// getter (accessor) - setter (mutator)
//	string getManufacturer();
//	void setManufacture(string);
//
//	string getProcessor();
//	void setProcessor(string);
//	
//	double getScreenSize();
//	void setScreenSize(double);
//	
//	string getColor();
//	void setColor(string);
//	
//	bool getIsNew();
//	void setIsNew(bool);
//
//	// input - output
//	void input();
//	void output();
//
//	// constructor
//	Laptop();
//	Laptop(string, string, double, string, bool);
//};
//
//int main() {
//
//	Laptop laptop1, laptop2("Dell","Intel i5", 15.6, "Black",true);
//
//	laptop1.input();
//	
//	cout << "\nLAPTOP 1:";
//	laptop1.output();
//
//	cout << "\nLAPTOP 2:";
//	laptop2.output();
//	
//
//	return 0;
//}
//
//string Laptop::getManufacturer()
//{
//	return manufacturer;
//}
//
//void Laptop::setManufacture(string s)
//{
//	manufacturer = s;
//}
//
//string Laptop::getProcessor()
//{
//	return processor;
//}
//
//void Laptop::setProcessor(string s)
//{
//	processor = s;
//}
//
//double Laptop::getScreenSize()
//{
//	return screenSize;
//}
//
//void Laptop::setScreenSize(double d)
//{
//	screenSize = d;
//}
//
//string Laptop::getColor()
//{
//	return color;
//}
//
//void Laptop::setColor(string s)
//{
//	color = s;
//}
//
//bool Laptop::getIsNew()
//{
//	return isNew;
//}
//
//void Laptop::setIsNew(bool b)
//{
//	isNew = b;
//}
//
//Laptop::Laptop()
//{
//	manufacturer = "Default Manufacturer";
//	processor = "Default Processor";
//	screenSize = 14;
//	color = "Default Color";
//	isNew = true;
//}
//
//Laptop::Laptop(string m, string p, double s, string c, bool n)
//{
//	manufacturer = m;
//	processor = p;
//	screenSize = s;
//	color = c;
//	isNew = n;
//}
//
//void Laptop::input() {
//
//	cout << "Enter an Manufacturer: ";
//	getline(cin, manufacturer);
//	
//	cout << "Enter a Processor: ";
//	getline(cin, processor);
//
//	cout << "Enter a Screen Size: ";
//	cin >> screenSize;
//	cin.ignore();
//
//	cout << "Enter a Color: ";
//	getline(cin, color);
//
//	cout << "Is it New (0 for No - 1 for Yes): ";
//	cin >> isNew;
//	cin.ignore();
//}
//
//void Laptop::output() {
//	cout << "\nManufacturer: " << manufacturer
//		<< "\nProcessor: " << processor
//		<< "\nScreen Size: " << screenSize
//		<< "\nColor: " << color
//		<< "\nNew: " << (isNew ? "Yes": "No")
//		<< endl;
//};