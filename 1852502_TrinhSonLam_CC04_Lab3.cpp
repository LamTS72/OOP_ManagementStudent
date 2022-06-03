//Author : Trinh Son Lam 1852502 CC04
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include<conio.h>
#include<iomanip>
using namespace std;


class Student {
private:
	string name;
	float score;
public:
	Student() {
		this->name = "";
		this->score = 0.0;
	}
	Student(string name, float score) {
		this->name = name;
		this->score = score;
	}
	string getName() {
		return name;
	}
	float getScore() {
		return score;
	}
	void setName(string name) {
		this->name = name;
	}
	void setScore(float score) {
		this->score = score;
	}
	void display() {
		cout << setw(30) << left << name;
		cout << setw(25) << right <<score;
		cout << endl;
	}
	~Student() {};

};

 //ADDITION DATA OF STUDENTS FROM KEYBOARD
int getData(Student* sv, int numofStd, int sumStd) {
	string gname;
	float gscore;
	if (sumStd == 0) {// if your list is empty
		for (int i = 0; i < numofStd; i++) {
			cout << "Enter name of student [" << i + 1 << "]: ";
			cin.ignore(1);
			cin >> gname;
			(sv + i)->setName(gname); // you should to input name with no space because we are using char with example :TrinhSonLam
			cout << endl;
			cout << "Enter score of " << (sv + i)->getName() << ": ";
			cin.ignore(1);
			cin >> gscore;
			(sv + i)->setScore(gscore);
			cout << endl;
			sumStd += 1;
		}
	}
	else {

		for (int i = 0; i < numofStd; i++) {
			cout << "Enter name of student [" << i + 1 << "]: ";
			cin.ignore(1);
			cin >> gname;
			(sv + i)->setName(gname); // you should to input name with no space because we are using char with example :TrinhSonLam
			cout << endl;
			cout << "Enter score of " << (sv + i)->getName() << ": ";
			cin.ignore(1);
			cin >> gscore;
			(sv + i)->setScore(gscore);
			cout << endl;
			sumStd += 1;
		}

	}
	return sumStd; //that means total of students in list
}

//THIS FUNCTION HELP YOU FIND STUDENTS WHO HAVE THE HIGHEST SCORE
void showbeststudent(Student* sv, int sumStd) {
	if (sumStd == 0) {
		cout << "List is empty!!!\n";

	}
	else {
		
		float highest = sv->getScore();
		for (int i = 0; i < sumStd; i++) {//traversal list and compare each score 
			if ((sv + i)->getScore() > highest) {
				highest = (sv + i)->getScore();
			}
		}
		
		for (int i = 0; i < sumStd; i++) {
				if (highest == (sv + i)->getScore()) {
					cout << setw(5) << left << i + 1;
					(sv+i)->display();
				}
			}
			cout << endl;
		}
}

// COMPARISON 2 NAME BETWEEN KEYBOARD AND DATA LIST
bool checkExist(Student* sv, string findname) {
	for (int i = 0; i < 100; i++) {
		if (sv->getName() == findname) return true;
		else return false;
	}
}

// SEARCH AND DELETE IF DATA EXIST
int removeData(Student* sv, string findname, int sumStd) {
	if (sumStd == 0) { // check empty of list
		cout << "Student doesnt exist!!!\n";
	}
	else {
		bool found = false;
		int i = 0;
		for (i = 0; i < sumStd; i++) { //traversal array list of students
			if (checkExist(sv+i, findname) == true) { // check student name in list
				found = true;
				break;
			}
		}
		if (found == true) {
			for (int j = i; j < sumStd; j++) {
				sv[j] = sv[j + 1]; //swap position 
				sv[j + 1].~Student();
			}
			found = false;
			sumStd--; // reducing number of students after deleting
			cout << "\nFounded: " << findname << endl;//after remove student you need to display again to check list in case 3
			cout << "And Deleted student!!!\n";
		}
		else cout << "Student doesnt exist!!!\n";

	}
	return sumStd; //that means total of students in list
}

//MENU SELECTION FOR YOU
void menu() {
	cout << "*=====================****========================*\n";
	cout << "*=====================MENU========================*\n";
	cout << "*1.Add student's name                             *\n";
	cout << "*2.Remove student's name                          *\n";
	cout << "*3.Display list of students                       *\n";
	cout << "*4.Display the best students                      *\n";
	cout << "*5.Exit                                           *\n";
	cout << "***************************************************\n";
}

// THIS FUNCTION HELP YOU CLEAR SCREEN AND THEN INPUT SELECTION AGAIN 
void pressAnyKey() {
	cout << "\nPress Any Key";
	_getch();
	system("cls");
}

int main() {
	Student *stu = new Student[100];
	int option; // what you select
	int total = 0; // total number of students
	int number; // that means number of students you want to add
	string searchname;// that means name of student that we find
	while (true) {
		cout << "************STUDENT MANAGEMENT PROGRAM*************\n";
		menu();
		cout << "Enter your choice: ";
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1://add
			cout << "Enter number of student: ";
			cin >> number;
			total = getData(stu+total,number,total);
			cout << "Addition is completed!!!\n";
			cout << total;
			pressAnyKey();
			break;
		case 2:
			cout << "Enter student's name to search: ";
			cin >> searchname;
			total = removeData(stu, searchname, total);
			pressAnyKey();
			break;
		case 3:
			if (total == 0) {
				cout << "List is empty!!!\n";
			}
			else {
				cout << setw(5) << left << "STT";
				cout << setw(30) << left << "Full Name";
				cout << setw(25) << right << "Score";
				cout << endl;
				for (int i = 0; i < total; i++) {
					cout << setw(5) << left << i + 1;
					(stu+i)->display();
				}
				cout << endl;
			}
			pressAnyKey();
			break;
		case 4:
			cout << setw(5) << left << "STT";
			cout << setw(30) << left << "Full Name";
			cout << setw(25) << right << "Score";
			cout << endl;
			showbeststudent(stu, total);
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