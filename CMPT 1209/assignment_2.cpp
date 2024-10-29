#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
using namespace std;

class PersonData {
protected:
	string lastName, firstName, address, city, state, zip, phone;

public:
	string getLastName() const {
		return lastName;
	}
	void setLastName(string s) {
		lastName = s;
	}
	string getFirstName() const {
		return firstName;
	}
	void setFirstName(string s) {
		firstName = s;
	}
	string getAddress() const {
		return address;
	}
	void setAddress(string s) {
		address = s;
	}
	string getCity() const {
		return city;
	}
	void setCity(string s) {
		city = s;
	}
	string getState() const {
		return state;
	}
	void setState(string s) {
		state = s;
	}
	string getZip() const {
		return zip;
	}
	void setZip(string s) {
		zip = s;
	}
	string getPhone() const {
		return firstName;
	}
	void setPhone(string s) {
		phone = s;
	}

	PersonData() {
		lastName = "default";
		firstName = "default";
		address = "default";
		city = "default";
		state = "default";
		zip = "default";
		phone = "default";
	}

	PersonData(string ln, string fn, string a, string c, string s, string z, string p) {
		lastName = ln;
		firstName = fn;
		address = a;
		city = c;
		state = s;
		zip = z;
		phone = p;
	}

	void personDataInput() {
		cout << "Last Name: ";
		getline(cin, lastName);
		cout << "First Name: ";
		getline(cin, firstName);
		cout << "Address: ";
		getline(cin, address);
		cout << "City: ";
		getline(cin, city);
		cout << "State: ";
		getline(cin, state);
		cout << "Zip: ";
		getline(cin, zip);
		cout << "Phone: ";
		getline(cin, phone);
	}

	void personDataOutput() const {
		cout << "\n---------- Person Info ----------"
			<< "\nLast Name: " << lastName << "\t\tFirst Name: " << firstName
			<< "\nAddress: " << address << "\tCity: " << city
			<< "\nState: " << state << "\tZip: " << zip << "\tPhone: " << phone
			<< endl;
	}
};

class CustomerData : public PersonData {
protected:
	int customerNumber;
	bool mailingList;

public:
	int getCustomerNumber() const {
		return customerNumber;
	}
	void setCustomerNumber(int n) {
		customerNumber = n;
	}
	bool getMailingList() const {
		return mailingList;
	}
	void setMailingList(bool b) {
		mailingList = b;
	}

	CustomerData() :PersonData() {
		customerNumber = 00000;
		mailingList = false;
	}

	CustomerData(string ln, string fn, string a, string c, string s, string z, string p,
		int cn, bool ml) :PersonData(ln, fn, a, c, s, z, p) {
		lastName = ln;
		firstName = fn;
		address = a;
		city = c;
		state = s;
		zip = z;
		phone = p;

		customerNumber = cn;
		mailingList = ml;
	}

	void createMembership(const PersonData p) {
		lastName = p.getLastName();
		firstName = p.getFirstName();
		address = p.getAddress();
		city = p.getCity();
		state = p.getState();
		zip = p.getZip();
		phone = p.getPhone();

		customerNumber = 11111 + (rand() % 10000);

		string _mailing;

		cout << "\nAdd to Mailing List? (Y/N): ";
		getline(cin, _mailing);

		while (!(_mailing.length() == 1 && (char(toupper(_mailing[0])) == 'Y' || char(toupper(_mailing[0])) == 'N'))) {
			cout << "\nInvalid input. 'Y' for Yes or 'N' for No only!\n";
			cout << "Add to Mailing List? (Y/N): ";
			getline(cin, _mailing);
		}

		mailingList = (_mailing == "Y" || _mailing == "y") ? true : false;

	}

	void customerDataOutput() const {
		personDataOutput();
		cout << "\nCustomer Number: " << customerNumber
			<< "\nIn Mailing List?: " << (mailingList ? "Yes" : "No")
			<< endl;
	}
};

class PreferredCustomer : public CustomerData {
protected:
	double purchasesAmount, discountLevel;
	// purchasesAmount: sum of all purchases up to date
	// discountLevel: discount % in the next bill
	// 1st buy $500 -> trigger -> current discount = 0%
	// 2nd buy $400 -> current discount = 5% | total: $900 -> next bill discount = 5%
	// 3rd buy $150 -> current discount = 5% | total: $1,050 -> next bill discount = 6%

public:
	double getPurchasesAmount() const {
		return purchasesAmount;
	}
	void setPurchasesAmount(double d) {
		purchasesAmount = d;
	}
	double getDiscountLevel() const {
		return discountLevel;
	}
	void setDiscountLevel(double d) {
		discountLevel = d;
	}

	PreferredCustomer() : CustomerData() {
		purchasesAmount = 0.0;
		discountLevel = 0.0;
	}

	PreferredCustomer(string ln, string fn, string a, string c, string s, string z, string p,
		int cn, bool ml,
		double pa) : CustomerData(ln, fn, a, c, s, z, p, cn, ml) {
		lastName = ln;
		firstName = fn;
		address = a;
		city = c;
		state = s;
		zip = z;
		phone = p;
		customerNumber = cn;
		mailingList = ml;

		purchasesAmount = pa;
		calculateDiscountLevel(purchasesAmount);
	}

	void calculateDiscountLevel(double _purchasesAmount) {
		if (_purchasesAmount >= 500 && _purchasesAmount < 1000) {
			discountLevel = 0.05;
		}
		else if (_purchasesAmount >= 1000 && _purchasesAmount < 1500) {
			discountLevel = 0.06;
		}
		else if (_purchasesAmount >= 1500 && _purchasesAmount < 2000) {
			discountLevel = 0.07;
		}
		else if (_purchasesAmount >= 2000) {
			discountLevel = 0.10;
		}
		else {
			discountLevel = 0.0;
		}
	}

	void addPurchase() {
		string _addMore;
		double _purchase;

		do {
			cout << "\nToday purchase amount: $";
			cin >> _purchase;

			while (_purchase < 0) {
				cout << "\nInvalid purchase amount! Sale figures should be >= $0.00!";
				cout << "\nToday purchase amount: $";
				cin >> _purchase;
			}

			purchasesAmount += _purchase;
			calculateDiscountLevel(purchasesAmount);

			cin.ignore();
			cout << "Add another Purchase? (Y/N): ";
			getline(cin, _addMore);

			while (_addMore.length() != 1 && !(char(toupper(_addMore[0])) == 'Y' || char(toupper(_addMore[0])) == 'N')) {
				cout << "\nInvalid input. 'Y' for Yes or 'N' for No only!\n";
				cout << "Add another Purchase ? (Y/N): ";
				getline(cin, _addMore);
			}

			if (_addMore == "N" || _addMore == "n") { break; }

		} while (true);

	}

	void addPreferredCustomer(const CustomerData c) {
		lastName = c.getLastName();
		firstName = c.getFirstName();
		address = c.getAddress();
		city = c.getCustomerNumber();
		state = c.getState();
		zip = c.getZip();
		phone = c.getPhone();
		customerNumber = c.getCustomerNumber();
		mailingList = c.getMailingList();

		addPurchase();
	}

	void preferredCustomerOutput() const {
		cout.imbue(locale(""));
		cout << "\n--------------------------------------"
			<< "\nTotal Purchases Amount: $" << fixed << setprecision(2) << purchasesAmount
			<< "\nDiscount Level on Next Purchase: " << setprecision(0) <<  discountLevel * 100 << "%"
			<< endl;
	}
};

int main() {

	PersonData personA, personB("Rock", "Black", "50 Hudson Yards", "New York", "NY", "10001", "212-810-5800");
	CustomerData customerA, customerB;
	PreferredCustomer preferredB;

	// For entering Person class test
	//personA.personDataInput();
	//customerA.createMembership(personA);
	//customerA.customerDataOutput();

	customerB.personDataOutput();
	customerB.createMembership(personB);
	customerB.customerDataOutput();

	preferredB.addPreferredCustomer(customerB);
	preferredB.preferredCustomerOutput();


	return 0;
}