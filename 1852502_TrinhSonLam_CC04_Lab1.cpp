//Author : Trinh Son Lam 1852502 CC04
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include<conio.h>
using namespace std;


struct Student {
	char name[100];
};
void getData(Student &sv){// input data from keyboard
	cin.ignore(1); 
	cin>>sv.name; // you should to input name with no space because we are using char
	cout << endl;
	
}

void display(Student &sv) { // show names in list
	
	cout << "\t" << sv.name;
}
void pressAnyKey() { // this function help you clear data that you input and back to menu
	cout << "\nPress Any Key";
	_getch();
	system("cls");
}

bool checkExist(Student &sv, char findname[100]){
	for (int i = 0; i < 100; i++) {
		if (sv.name[i] == findname[i]) return true;
		else return false;
	}
}
void menu() { //menu with some selection for you
	cout << "*=====================****========================*\n";
	cout << "*=====================MENU========================*\n";
	cout << "*1.Add student's name                             *\n";
	cout << "*2.Remove student's name                          *\n";
	cout << "*3.Display list of students                       *\n";
	cout << "*4.Exit                                           *\n";
	cout << "***************************************************\n";
}
int main() {
	
	int option; // what you select
	int total = 0; // total number of students
	int number; // that means number of students you want to add 
	char searchname[100];// that means name of student that we find
	Student arrSt[100];
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
			if (total == 0) {// if your list is empty
				cout << "Enter number of student: ";
				cin >> number;
				for (int i = 1; i <= number; i++) {
					cout << "Enter name of student [" << i << "]: ";
					getData(arrSt[i]);
					total += 1;
				}
			}
			else { // if your list have some elements
				cout << "Enter number of student: ";
				cin >> number;
				for (int i = 1; i <= number; i++) {
					cout << "Enter name of student [" << i << "]: ";
					getData(arrSt[total+1]); // elements are added and updated followed by initial elements 
					total += 1;
				}
			}
			cout << "Addition is completed!!!\n";
			pressAnyKey();
			break;
		case 2: //search and remove
			if (total == 0) { // check empty of list
				cout << "Student doesnt exist!!!\n";
			}
			else {
				bool found = false;
				cout << "Enter student's name to search: ";
				cin >> searchname;
				int i = 1;
				for ( i = 1; i <=total; i++) { //traversal array list 
					if (checkExist(arrSt[i], searchname) == true) { // check student name in list
						found = true;
						break;
					}
				}
				if (found == true) {
					for (int j = i; j < total ; j++) {
						arrSt[j] = arrSt[j + 1]; //swap position when deleting
						
					}
					found = false;
					total--; // reducing number of students after deleting
					cout << "\nFounded: "<<searchname<<endl;//after remove student you need to display again to check list in case 3
					cout<<"And Deleted student!!!\n";
				}
				else cout << "Student doesnt exist!!!\n";
			}
			pressAnyKey();
			break;
		case 3://show list 
			if (total == 0) {
				cout << "List is empty!!!\n";
			}
			else {
				cout << "\nSTT\tFull Name";
				for (int i = 1; i <= total; i++) {
					cout << "\n" << i;
					display(arrSt[i]);

				}
			}
			cout << endl;
			cout << "\nList of students is showed\n";
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
