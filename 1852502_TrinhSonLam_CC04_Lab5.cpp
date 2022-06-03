//Author : Trinh Son Lam 1852502 CC04
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include<conio.h>
#include<iomanip>
using namespace std;

struct semesterUni {
	int assignment;
	int test;
	int exam;
	semesterUni(){
		assignment = 3;
		test = 2;
		exam = 1;
	}
};

struct semesterCollege {
	int assignment;
	int test;
	int exam;
	semesterCollege() {
		assignment = 1;
		test = 1;
		exam = 1;
	}
};

class Student {
private:
	string student_name;
	string date_of_birth;
	string school_name;
	string course_name;
	public:
	Student() {
		this->student_name = "";
		this->date_of_birth = "";
	}
	Student(string name, string birthday, string school, string course) {
		this->student_name = name;
		this->date_of_birth = birthday;
		this->school_name = school;
		this->course_name = course;
	}
	string getName() {
		return student_name;
	}
	string getBirthday() {
		return date_of_birth;
	}
	string getSchool() {
		return school_name;
	}
	string getCourse() {
		return course_name;
	}
	void setName(string name) {
		this->student_name = name;
	}
	void setBirthday(string birthday) {
		this->date_of_birth = birthday;
	}
	void setSchool(string school) {
		this->school_name = school;
	}
	void setCourse(string course) {
		this->course_name = course;
	}

	~Student() {};

};

class UniStudent : public Student {
private:
	int num_of_semester;
	semesterUni* list_SemesterUni;
public:
	UniStudent() {
		this->num_of_semester = 8;
		this->list_SemesterUni = new semesterUni[8];
	}
	int add_Student(UniStudent *stu, int numofStd, int sumStd);
	void display(UniStudent* stu, int i);
};

int UniStudent::add_Student(UniStudent *stu,int numofStd, int sumStd) {
	string aname;
	string abirth;
	string aschool;
	string acourse;
	if (sumStd == 0) {// if your list is empty
		for (int i = 0; i < numofStd; i++) {
			cout << "Enter name of student [" << i + 1 << "]: ";
			cin.ignore(0);
			cin >> aname;				// you should to input name with
			stu[i].setName(aname);  //no space because we are using char with example :TrinhSonLam
			cout << endl;
			cout << "Enter date-of-birth of " << stu[i].getName() << ": ";
			cin.ignore(0);
			cin >> abirth;
			stu[i].setBirthday(abirth);
			cout << endl;
			cout << "Enter school-name of " << stu[i].getName() << ": ";
			cin.ignore(0);
			cin >> aschool;
			stu[i].setSchool(aschool);
			cout << endl;
			cout << "Enter course-name of " << stu[i].getName() << ": ";
			cin.ignore(0);
			cin >> acourse;
			stu[i].setCourse(acourse);
			cout << endl;
			sumStd += 1;
		}
	}
	else {
		for (int i = 0; i < numofStd; i++) {
			cout << "Enter name of student [" << i + 1 << "]: ";
			cin.ignore(0);
			cin >> aname;				// you should to input name with
			stu[i+sumStd].setName(aname);  //no space because we are using char with example :TrinhSonLam
			cout << endl;
			cout << "Enter date-of-birth of " << stu[i+sumStd].getName() << ": ";
			cin.ignore(0);
			cin >> abirth;
			stu[i+sumStd].setBirthday(abirth);
			cout << endl;
			cout << "Enter school-name of " << stu[i+sumStd].getName() << ": ";
			cin.ignore(0);
			cin >> aschool;
			stu[i+sumStd].setSchool(aschool);
			cout << endl;
			cout << "Enter course-name of " << stu[i+sumStd].getName() << ": ";
			cin.ignore(0);
			cin >> acourse;
			stu[i+sumStd].setCourse(acourse);
			cout << endl;
			sumStd += 1;
		}

	}
	return sumStd; //that means total of students in list
}

void UniStudent::display(UniStudent *stu, int i) {
	cout << setw(25) << left << stu[i].getName();
	cout << setw(30) << left << stu[i].getBirthday();
	cout << setw(35) << left << stu[i].getSchool();
	cout << setw(40) << left << stu[i].getCourse();
	cout << endl;
}


class CollegeStudent : public Student {
private:
	int num_of_semester;
	semesterCollege* list_SemesterCollege;
public:
	CollegeStudent() {
		this->num_of_semester = 4;
		this->list_SemesterCollege = new semesterCollege[4];
	}
	int add_Student(CollegeStudent* stu, int numofStd, int sumStd);
	void display(CollegeStudent* stu, int i);
};

int CollegeStudent::add_Student(CollegeStudent* stu, int numofStd, int sumStd) {
	string aname;
	string abirth;
	string aschool;
	string acourse;
	if (sumStd == 0) {// if your list is empty
		for (int i = 0; i < numofStd; i++) {
			cout << "Enter name of student [" << i + 1 << "]: ";
			cin.ignore(0);
			cin >> aname;				// you should to input name with
			stu[i].setName(aname);  //no space because we are using char with example :TrinhSonLam
			cout << endl;
			cout << "Enter date-of-birth of " << stu[i].getName() << ": ";
			cin.ignore(0);
			cin >> abirth;
			stu[i].setBirthday(abirth);
			cout << endl;
			cout << "Enter school-name of " << stu[i].getName() << ": ";
			cin.ignore(0);
			cin >> aschool;
			stu[i].setSchool(aschool);
			cout << endl;
			cout << "Enter course-name of " << stu[i].getName() << ": ";
			cin.ignore(0);
			cin >> acourse;
			stu[i].setCourse(acourse);
			cout << endl;
			sumStd += 1;
		}
	}
	else {
		for (int i = 0; i < numofStd; i++) {
			cout << "Enter name of student [" << i + 1 << "]: ";
			cin.ignore(0);
			cin >> aname;				// you should to input name with
			stu[i + sumStd].setName(aname);  //no space because we are using char with example :TrinhSonLam
			cout << endl;
			cout << "Enter date-of-birth of " << stu[i + sumStd].getName() << ": ";
			cin.ignore(0);
			cin >> abirth;
			stu[i + sumStd].setBirthday(abirth);
			cout << endl;
			cout << "Enter school-name of " << stu[i + sumStd].getName() << ": ";
			cin.ignore(0);
			cin >> aschool;
			stu[i + sumStd].setSchool(aschool);
			cout << endl;
			cout << "Enter course-name of " << stu[i + sumStd].getName() << ": ";
			cin.ignore(0);
			cin >> acourse;
			stu[i + sumStd].setCourse(acourse);
			cout << endl;
			sumStd += 1;
		}

	}
	return sumStd; //that means total of students in list
}

void CollegeStudent::display(CollegeStudent* stu, int i) {
	cout << setw(25) << left << stu[i].getName();
	cout << setw(30) << left << stu[i].getBirthday();
	cout << setw(35) << left << stu[i].getSchool();
	cout << setw(40) << left << stu[i].getCourse();
	cout << endl;
}

// THIS FUNCTION HELP YOU CLEAR SCREEN AND THEN INPUT SELECTION AGAIN 
void pressAnyKey() {
	cout << "\nPress Any Key";
	_getch();
	system("cls");
}




void University(UniStudent* BK_uni) {
	 
	int option1; // what you select
	int total1 = 0; // total number of students
	int number1; // that means number of students you want to add
	do {
		cout << "*==================UNIVERSITY=====================*\n";
		cout << "*=====================MENU========================*\n";
		cout << "*1.Add student's name                             *\n";
		cout << "*2.Display list of students                       *\n";
		cout << "*3.Visit menu                                     *\n";
		cout << "***************************************************\n";
		cout << "Enter your choice: ";
		cin >> option1;
		cin.ignore();
		switch (option1)
		{
		case 1://add
			cout << "Enter number of student: ";
			cin >> number1;
			total1 = BK_uni->add_Student(BK_uni, number1, total1);
			cout << "Addition is completed!!!\n";
			cout << "Total of Students in list of university " << total1;
			pressAnyKey();
			break;
		case 2://showlist
			if (total1 == 0) {
				cout << "List is empty!!!\n";
			}
			else {
				cout << setw(5) << left << "STT";
				cout << setw(25) << left << "Full Name";
				cout << setw(30) << left << "Date-of-birth";
				cout << setw(35) << left << "School";
				cout << setw(40) << left << "Course";
				cout << endl;
				for (int i = 0; i < total1; i++) {
					cout << setw(5) << left << i + 1;
					BK_uni->display(BK_uni, i);
				}
				cout << endl;
			}
			pressAnyKey();
			break;
		default://exit
			
			break;
			
		}
	} while (option1 != 3);
}

void College(CollegeStudent* BK_college) {
	
	int option2; // what you select
	int total2 = 0; // total number of students
	int number2; // that means number of students you want to add
	do {
		cout << "*===================COLLEGE=======================*\n";
		cout << "*=====================MENU========================*\n";
		cout << "*1.Add student's name                             *\n";
		cout << "*2.Display list of students                       *\n";
		cout << "*3.Visit menu                                     *\n";
		cout << "***************************************************\n";
		cout << "Enter your choice: ";
		cin >> option2;
		cin.ignore();
		switch (option2)
		{
		case 1://add
			cout << "Enter number of student: ";
			cin >> number2;
			total2 = BK_college->add_Student(BK_college, number2, total2);
			cout << "Addition is completed!!!\n";
			cout << "Total of Students in list of college " << total2;
			pressAnyKey();
			break;
		case 2://showlist
			if (total2 == 0) {
				cout << "List is empty!!!\n";
			}
			else {
				cout << setw(5) << left << "STT";
				cout << setw(25) << left << "Full Name";
				cout << setw(30) << left << "Date-of-birth";
				cout << setw(35) << left << "School";
				cout << setw(40) << left << "Course";
				cout << endl;
				for (int i = 0; i < total2; i++) {
					cout << setw(5) << left << i + 1;
					BK_college->display(BK_college, i);
				}
				cout << endl;
			}
			pressAnyKey();
			break;
		default://exit
			break;
		}
	} while (option2 != 3);
}
//MENU SELECTION FOR YOU


int main() {
	UniStudent* BK_uni = new UniStudent[2000]; //capacity of university
	CollegeStudent* BK_college = new CollegeStudent[1000];	//capacity og college
	int option; // what you select
	while (true) {
		cout << "************STUDENT MANAGEMENT PROGRAM*************\n";
		cout << "*=====================****========================*\n";
		cout << "*1.University                                     *\n";
		cout << "*2.College                                        *\n";
		cout << "*3.Exit                                           *\n";
		cout << "***************************************************\n";
		cout << "Enter your choice: ";
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1://add
			University(BK_uni);
			pressAnyKey();
			break;
		case 2:
			College(BK_college);
			pressAnyKey();
			break;
		default:
			char sel;//select
			cout << "Do you want to exit(y/n): ";
			cin >> sel;
			if (sel == 'y' || sel == 'Y') {
				return 0;
			}
			else pressAnyKey();
			break;
		}
	}
	return 0;
}