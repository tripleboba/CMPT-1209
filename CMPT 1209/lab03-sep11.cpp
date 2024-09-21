//// WITH LECTURE
//#include <iostream>
//#include <string>
//using namespace std;
//
///* CMPT 1209
//* PRELAB 03 - Sep 11
//*
//* Write a program that uses MovieData structure storing
//* - Title
//* - Director
//* - Year Released
//* - Running Time (in mins)
//* Create 2 MovieData obj{}
//* Ask user to enter info > Store values > Display info each {}
//*/
//
////struct
//class MovieData {
//	string title;
//	string director;
//	int releasedYear;
//	double minsRunningTime;
//};
//
////int main() {
////
////	int const N_MOVIES = 2;
////	MovieData movies[N_MOVIES] = {};
////
////	for (int i = 0; i < N_MOVIES; i++) {
////		MovieData _movie;
////
////		// get causing the program to ignore all below cin commands
////		// cin.ignore() 
////
////		cout << "Title of " << i + 1 << " movie: ";
////		getline(cin, _movie.title);
////
////		cout << "Director Name: ";
////		getline(cin, _movie.director);
////
////		cout << "Released Year: ";
////		cin >> _movie.releasedYear;
////
////		cout << "Running Time (mins): ";
////		cin >> _movie.minsRunningTime;
////
////		// !!
////		cin.ignore();
////		movies[i] = _movie;
////
////		cout << endl;
////	}
////
////	cout << "----------------------------";
////	for (int i = 0; i < N_MOVIES; i++) {
////		cout << "\nMovie " << i + 1 << ": "
////			<< "\nTitle: " << movies[i].title
////			<< "\nDirector: " << movies[i].director
////			<< "\nReleased Year: " << movies[i].releasedYear
////			<< "\nRunning Time (mins): " << movies[i].minsRunningTime
////			<< endl;
////	}
////
////	return 0;
////}
//
//
///* LECTURE - Wed, Sep 11
//* struct vs class
//*
//* struct
//* - public
//*
//* class
//* - local | only inside a class
//* - member of the class is default to be private
//* - can be defined to be public -> turn into struct's behaviors
//* - public MovieData */
//
//class MovieData {
//
//	// private: -- default | no need to defined
//	string title; //= "Default Title";
//	string director;
//	int releasedYear;
//	double minsRunningTime;
//
//public:
//	string getTitle(); // const; 
//	// setter(), input(), constructor() can't be defined with const as child vars are needed to be manipulated
//	void setTitle(string);
//	string getDirector();
//	void setDirector(string);
//	int getReleasedYear();
//	void setReleasedYear(int);
//	double getMinsRunningTime();
//	void setMinsRunningTime(double);
//
//	void input();
//	void output(); // const;
//
//	// MovieData(); // constructor
//	// MovieData(string, string) with defined
//	// 
//	// if defined MovieData wrongCall = MovieData("field1"); in main
//	// won't work as no constructor with 1 param is declared ^
//	
//	// fix?
//	// set default value to constructor()'s params
//	// MovieData(string, string = "Default"); -> set 2nd param = "Default" when the 2nd param is missing
//	// -> wrongCall {title = "field1",
//	// director = "Default"}
//	// default to param needs to start from the last up to the 1st as won't work if 1st has default set but the rest is empty
//	// not working:  MovieData(string = "Default", string);
//	// will work: MovieData(int, bool, string = "default1", string = "default2");
//
//	// if all params in constructor() are set with default values 
//	// -> console error -> class MovieData has more than 1 default constructor()
//	// at least 1 param need to be left without setting default value
//
//
//
//};
///*
//* Constructor
//* can have multi constructor with different params
//*/
////MovieData::MovieData() {
////	title = "Constructor's Title";
////	director = "Constructor's Director";
////	releasedYear = 1990;
////	minsRunningTime = 120.03;
////}
//
///*
//* make the class's vars private but accessible
//*  but accessible for what? read or write?
//* read -> getter === accessor || string get(){ return; }
//* write -> setter === mutator || void set(){ }
//*/
//string MovieData::getTitle() {
//	return title;
//}
//void MovieData::setTitle(string t) {
//	title = t;
//}
//string MovieData::getDirector() {
//	return director;
//}
//void MovieData::setDirector(string d) {
//	director = d;
//}
//int MovieData::getReleasedYear() {
//	return releasedYear;
//}
//void MovieData::setReleasedYear(int y) {
//	releasedYear = y;
//}
//double MovieData::getMinsRunningTime() {
//	return minsRunningTime;
//}
//void MovieData::setMinsRunningTime(double t) {
//	minsRunningTime = t;
//}
//
///*
//* Using class() to read inputs from user
//*/
//void MovieData::input() {
//	cout << "Title of movie: ";
//	getline(cin, title); // set input directly to title var
//
//	cout << "Director Name: ";
//	getline(cin, director);
//
//	cout << "Released Year: ";
//	cin >> releasedYear;
//
//	cout << "Running Time (mins): ";
//	cin >> minsRunningTime;
//
//	cin.ignore();
//}
//void MovieData::output() {
//	cout << "\nTitle: " << title
//		<< "\nDirector: " << director
//		<< "\nReleased Year: " << releasedYear
//		<< "\nRunning Time (mins): " << minsRunningTime
//		<< endl;
//}
//
///*
//* Calling input() output() from class()
//*/
//
//int main() {
//	MovieData movie1, movie2;
//	movie1.input(); movie2.input();
//
//	cout << "\nMovie 1:"; movie1.output();
//	cout << "\nMovie 2:"; movie2.output();
//
//	return 0;
//}