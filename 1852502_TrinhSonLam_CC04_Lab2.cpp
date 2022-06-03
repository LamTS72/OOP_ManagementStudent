//Author : Trinh Son Lam 1852502 CC04
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include<conio.h>
#include<iomanip>
using namespace std;


struct Student {
	char name[100];
	float score;
};
// ADDITION DATA OF STUDENTS FROM KEYBOARD
int getData(Student* sv,int number, int sum) {
	if (sum == 0) {// if your list is empty
		for (int i = 0; i < number; i++) {
			cout << "Enter name of student [" << i + 1 << "]: ";
			cin.ignore(1);
			cin >> (sv+i)->name; // you should to input name with no space because we are using char with example :TrinhSonLam
			cout << endl;
			cout << "Enter score of " << (sv + i)->name << ": ";
			cin.ignore(1);
			cin >> (sv+i)->score;
			cout << endl;
			sum += 1;
		}
	}
	else {
		for (int i = 0; i < number; i++) {
			cout << "Enter name of student [" << i + 1 << "]: ";
			cin.ignore(1);
			cin >> (sv + i)->name; // you should to input name with no space because we are using char with example :TrinhSonLam
			cout << endl;
			cout << "Enter score of " << (sv + i)->name << ": ";
			cin.ignore(1);
			cin >> (sv + i)->score;
			cout << endl;
			sum += 1;
		}

	}
	return sum; //that means total of students in list
}
// COMPARISON 2 NAME BETWEEN KEYBOARD AND DATA LIST
bool checkExist(Student* sv, char findname[100]) {
	for (int i = 0; i < 100; i++) {
		if (sv->name[i] == findname[i]) return true;
		else return false;
	}
}
// SEARCH AND DELETE IF DATA EXIST
int removeData(Student* sv, char findname[100], int sum) {
	if (sum == 0) { // check empty of list
		cout << "Student doesnt exist!!!\n";
	}
	else {
		bool found = false;
		int i = 0;
		for (i = 0; i < sum; i++) { //traversal array list 
			if (checkExist(sv+i, findname) == true) { // check student name in list
				found = true;
				break;
			}
		}
		if (found == true) {
			for (int j = i; j < sum; j++) {
				sv[j] = sv[j + 1]; //swap position when deleting
			}
			found = false;
			sum--; // reducing number of students after deleting
			cout << "\nFounded: " << findname << endl;//after remove student you need to display again to check list in case 3
			cout << "And Deleted student!!!\n";
		}
		else cout << "Student doesnt exist!!!\n";

	}
	return sum; //that means total of students in list
}
// SHOW DATA LIST 
void display(Student* sv,int sum) { 
	if (sum == 0) {
		cout << "List is empty!!!\n";
	}
	else {
		cout << setw(5)<< left << "STT";
		cout << setw(30)<< left << "Full Name";
		cout << setw(25)<< right <<"Score";
		cout << endl;
		for (int i = 0; i < sum; i++) {
			cout << setw(5) <<left << i + 1;
			cout << setw(30)<<left << (sv + i)->name;
			cout << setw(25)<<right << (sv + i)->score;
			cout << endl;
		}
		cout << endl;
	}
	
}
//THIS FUNCTION HELP YOU FIND STUDENTS WHO HAVE THE HIGHEST SCORE
void showbeststudent(Student *sv , int sum){
	if (sum == 0) {
		cout << "List is empty!!!\n";

	}
	else {
		float highest = sv->score;
		for (int i = 0; i < sum; i++) {//traversal list and compare each score 
			if ((sv + i)->score > highest) {
				highest = (sv + i)->score;
			}
		}
		cout << setw(5) << left << "STT";
		cout << setw(30) << left << "Full Name";
		cout << setw(25) << right << "Score";
		cout << endl;
		for (int i = 0; i < sum; i++) {
			if (highest == (sv + i)->score) {
				cout << setw(5) << left << i + 1;
				cout << setw(30) << left << (sv + i)->name;
				cout << setw(25) << right << (sv + i)->score;
				cout << endl;
			}
		}
		cout << endl;
	}
}

// THIS FUNCTION HELP YOU CLEAR SCREEN AND THEN INPUT SELECTION AGAIN 
void pressAnyKey() { 
	cout << "\nPress Any Key";
	_getch();
	system("cls");
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
int main() {

	int option; // what you select
	int total = 0; // total number of students
	int numofSt; // that means number of students you want to add 
	char searchname[100];// that means name of student that we find
	Student* arrSt = new Student[100];
	while (true)
	{
		cout << "************STUDENT MANAGEMENT PROGRAM*************\n";
		menu();
		cout << "Enter your choice: ";
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1: //add
			cout << "Enter number of student: ";
			cin >> numofSt;
			total =getData(arrSt+total, numofSt, total);
			cout << "Addition is completed!!!\n";
			pressAnyKey();
			break;
		case 2: //remove
			cout << "Enter student's name to search: ";
			cin >> searchname;
			total=removeData(arrSt , searchname, total);
			pressAnyKey();
			break;
		case 3://show list 
			display(arrSt, total);
			cout << "\nList of students is showed!!!\n";
			pressAnyKey();
			break;
		case 4://best students
			showbeststudent(arrSt, total);
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
