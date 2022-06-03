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
	semesterUni() {
		assignment = 3;
		test = 2;
		exam = 1;
	}
	~semesterUni() {};

	int list_score_assignment[3];
	int list_score_test[2];
	int list_score_exam[1];

	void setScoreAssigment(int x, int y, int z) {
		list_score_assignment[0] = x;
		list_score_assignment[1] = y;
		list_score_assignment[2] = z;
	}
	int* getScoreAssigment() {
		return list_score_assignment;
	}
	void setScoreTest(int x, int y) {
		list_score_test[0] = x;
		list_score_test[1] = y;
	}
	int* getScoreTest() {
		return list_score_test;
	}
	void setScoreExam(int x) {
		list_score_exam[0] = x;
	}
	int* getScoreExam() {
		return list_score_exam;
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
	~semesterCollege() {};
	int list_score_assignment[1];
	int list_score_test[1];
	int list_score_exam[1];
	void setScoreAssigment(int x) {
		list_score_assignment[0] = x;
	}
	int* getScoreAssigment() {
		return list_score_assignment;
	}
	void setScoreTest(int x) {
		list_score_test[0] = x;
	}
	int* getScoreTest() {
		return list_score_test;
	}
	void setScoreExam(int x) {
		list_score_exam[0] = x;
	}
	int* getScoreExam() {
		return list_score_exam;
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
	virtual void DoAssignment() = 0;
	virtual void TakeTest() = 0;
	virtual void TakeExam() = 0;
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
	int add_Student(int sumStd);
	void display();
	void DoAssignment();
	void TakeTest();
	void TakeExam();
};

int UniStudent::add_Student(int sumStd) {
	string aname;
	string abirth;
	string aschool;
	string acourse;
	cout << "Enter name of student: ";
	cin.ignore(0);
	cin >> aname;				// you should to input name with
	setName(aname);  //no space because we are using char with example :TrinhSonLam
	cout << endl;
	cout << "Enter date-of-birth: ";
	cin.ignore(0);
	cin >> abirth;
	setBirthday(abirth);
	cout << endl;
	cout << "Enter school-name: ";
	cin.ignore(0);
	cin >> aschool;
	setSchool(aschool);
	cout << endl;
	cout << "Enter course-name: ";
	cin.ignore(0);
	cin >> acourse;
	setCourse(acourse);
	cout << endl;
	sumStd += 1;
	
	return sumStd; //that means total of students in list
}

void UniStudent::display() {
	cout << setw(25) << left << getName();
	cout << setw(25) << left << getBirthday();
	cout << setw(25) << left << getSchool();
	cout << setw(25) << left << getCourse();
	cout << setw(10) << left << " ";
	cout << setw(10) << left << " ";
	cout << setw(10) << left << " ";
	cout << setw(10) << left << " " << endl;
	for (int k = 0; k < this->num_of_semester; k++) {
		cout << setw(5) << left << " ";
		cout << setw(25) << left << " ";
		cout << setw(25) << left << " ";
		cout << setw(25) << left << " ";
		cout << setw(25) << left << " ";
		cout << setw(10) << left << k + 1;
		int *score_assignment = list_SemesterUni[k].getScoreAssigment();
		for (int j = 0; j < 3; j++) {
			cout << setw(10) << left << *(score_assignment + j);

		}
		int *score_test = list_SemesterUni[k].getScoreTest();
		for (int j = 0; j < 2; j++) {
			cout << setw(10) << left << *(score_test + j);
		}
		int *score_exam = list_SemesterUni[k].getScoreExam();
		for (int j = 0; j < 1; j++) {
			cout << setw(10) << left << *(score_exam) << endl;
		}
	}
}

void UniStudent::DoAssignment() {
	int random_scores_x;
	int random_scores_y;
	int random_scores_z;
	// Initialize random number generator.
	for (int j = 0; j < this->num_of_semester; j++) {
		for (int k = 0; k < 3; k++) {
			random_scores_x = (rand() % 10) + 1;
			random_scores_y = (rand() % 10) + 1;
			random_scores_z = (rand() % 10) + 1;
		}
		this->list_SemesterUni[j].setScoreAssigment(random_scores_x, random_scores_y, random_scores_z);
	}
}

void UniStudent::TakeTest() {
	int random_scores_x;
	int random_scores_y;
	// Initialize random number generator.
	for (int j = 0; j < this->num_of_semester; j++) {
		for (int k = 0; k < 2; k++) {
			random_scores_x = (rand() % 10) + 1;
			random_scores_y = (rand() % 10) + 1;
		}
		this->list_SemesterUni[j].setScoreTest(random_scores_x, random_scores_y);
	}
}
void UniStudent::TakeExam() {
	int random_scores_x;
	// Initialize random number generator.
	for (int j = 0; j < this->num_of_semester; j++) {
		for (int k = 0; k < 1; k++) {
			random_scores_x = (rand() % 10) + 1;
		}
		this->list_SemesterUni[j].setScoreExam(random_scores_x);
	}
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
	int add_Student(int sumStd);
	void display();
	void DoAssignment();
	void TakeTest();
	void TakeExam();
};

int CollegeStudent::add_Student(int sumStd) {
	string aname;
	string abirth;
	string aschool;
	string acourse;
	cout << "Enter name of student: ";
	cin.ignore(0);
	cin >> aname;				// you should to input name with
	setName(aname);  //no space because we are using char with example :TrinhSonLam
	cout << endl;
	cout << "Enter date-of-birth: ";
	cin.ignore(0);
	cin >> abirth;
	setBirthday(abirth);
	cout << endl;
	cout << "Enter school-name: ";
	cin.ignore(0);
	cin >> aschool;
	setSchool(aschool);
	cout << endl;
	cout << "Enter course-name: ";
	cin.ignore(0);
	cin >> acourse;
	setCourse(acourse);
	cout << endl;
	sumStd += 1;
	
	return sumStd; //that means total of students in list
}

void CollegeStudent::display() {
	cout << setw(25) << left << getName();
	cout << setw(25) << left << getBirthday();
	cout << setw(25) << left << getSchool();
	cout << setw(25) << left << getCourse();
	cout << setw(10) << left << " ";
	cout << setw(10) << left << " ";
	cout << setw(10) << left << " ";
	cout << setw(10) << left << " " << endl;
	for (int i = 0; i < this->num_of_semester; i++) {
		cout << setw(5) << left << " ";
		cout << setw(25) << left << " ";
		cout << setw(25) << left << " ";
		cout << setw(25) << left << " ";
		cout << setw(25) << left << " ";
		cout << setw(10) << left << i + 1;
		int* score_assignment = list_SemesterCollege[i].getScoreAssigment();
		for (int j = 0; j < 1; j++) {
			cout << setw(10) << left << *(score_assignment + j);
			cout << setw(10) << left << " ";
			cout << setw(10) << left << " ";

		}
		int* score_test = list_SemesterCollege[i].getScoreTest();
		for (int j = 0; j < 1; j++) {
			cout << setw(10) << left << *(score_test + j);
			cout << setw(10) << left << " ";
		}
		int* score_exam = list_SemesterCollege[i].getScoreExam();
		for (int j = 0; j < 1; j++) {
			cout << setw(10) << left << *(score_exam) << endl;
		}
	}
}
void CollegeStudent::DoAssignment() {
	int random_scores_x;
	// Initialize random number generator.
	for (int j = 0; j < this->num_of_semester; j++) {
		for (int k = 0; k < 1; k++) {
			random_scores_x = (rand() % 10) + 1;
			
		}
		this->list_SemesterCollege[j].setScoreAssigment(random_scores_x);
	}
}
void CollegeStudent::TakeTest(){
	int random_scores_x;
	
	// Initialize random number generator.
	for (int j = 0; j < this->num_of_semester; j++) {
		for (int k = 0; k < 1; k++) {
			random_scores_x = (rand() % 10) + 1;
			
		}
		this->list_SemesterCollege[j].setScoreTest(random_scores_x);
	}
}
void CollegeStudent::TakeExam() {
	int random_scores_x;
	// Initialize random number generator.
	for (int j = 0; j < this->num_of_semester; j++) {
		for (int k = 0; k < 1; k++) {
			random_scores_x = (rand() % 10) + 1;
		}
		this->list_SemesterCollege[j].setScoreExam(random_scores_x);
	}
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
		cout << "*3.Do assignments                                 *\n";
		cout << "*4.Do tests                                       *\n";
		cout << "*5.Do exams                                       *\n";
		cout << "*6.Visit menu                                     *\n";
		cout << "***************************************************\n";
		cout << "Enter your choice: ";
		cin >> option1;
		cout << endl;
		cin.ignore();
		switch (option1)
		{
		case 1://add
			cout << "Enter number of student: ";
			cin >> number1;
			cout << endl;
			if (total1 == 0) {// if your list is empty
				for (int i = 0; i < number1; i++) {
					cout << "Member:[" << i + 1 << "]"<<endl;
					total1 = BK_uni[i].add_Student(total1);
				}
			}
			else { // if list is non-empty
				for (int i = 0; i < number1; i++) {
					cout << "Member: [" << i + 1 << "]";
					total1 = BK_uni[i+total1].add_Student(total1);
				}
			}

			cout << "Addition is completed!!!\n";
			cout << "Total of Students in list of university " << total1;
			pressAnyKey();
			break;
		case 2://showlist
			if (total1 == 0) {
				cout << "List is empty!!!\n";
			}
			else {
				cout << setfill('-');
				cout << setw(175) << "-" << endl;
				cout << setfill(' ');
				cout << setw(5) << left << "STT";
				cout << setw(25) << left << "Full Name";
				cout << setw(25) << left << "Date-of-birth";
				cout << setw(25) << left << "School";
				cout << setw(25) << left << "Course";
				cout << setw(10) << left << "Semester";
				cout << setw(10) << left << "Assign_1";
				cout << setw(10) << left << "Assign_2";
				cout << setw(10) << left << "Assign_3";
				cout << setw(10) << left << "Test1";
				cout << setw(10) << left << "Test2";
				cout << setw(10) << left << "Exam";
				cout << endl;
				cout << setfill('-');
				cout << setw(175) << "-" << endl;
				cout << setfill(' ');
				
				for (int i = 0; i < total1; i++) {
					cout << setw(5) << left << i + 1;
					BK_uni[i].display();
				}
				
			}
			pressAnyKey();
			break;
		case 3:// you need to choose this case before you select display
			for (int i = 0; i < total1; i++) {
				BK_uni[i].DoAssignment();
			}
			pressAnyKey();
			break;
		case 4:// you need to choose this case before you select display
			for (int i = 0; i < total1; i++) {
				BK_uni[i].TakeTest();
			}
			pressAnyKey();
			break;
		case 5:// you need to choose this case before you select display
			for (int i = 0; i < total1; i++) {
				BK_uni[i].TakeExam();
			}
			pressAnyKey();
			break;
		default://exit

			break;

		}
	} while (option1 != 6 );
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
		cout << "*3.Do assignments                                 *\n";
		cout << "*4.Do tests                                       *\n";
		cout << "*5.Do exams                                       *\n";
		cout << "*6.Visit menu                                     *\n";
		cout << "***************************************************\n";
		cout << "Enter your choice: ";
		cin >> option2;
		cin.ignore();
		switch (option2)
		{
		case 1://add
			cout << "Enter number of student: ";
			cin >> number2;
			cout << endl;
			if (total2 == 0) {// if your list is empty
				for (int i = 0; i < number2; i++) {
					cout << "Member: [" << i + 1 << "]" << endl;;
					total2 = BK_college[i].add_Student(total2);
				}
			}
			else { // if list is non-empty
				for (int i = 0; i < number2; i++) {
					cout << "Member: [" << i + 1 << "]" << endl;;
					total2 = BK_college[i + total2].add_Student(total2);
				}
			}
			cout << "Addition is completed!!!\n";
			cout << "Total of Students in list of college " << total2;
			pressAnyKey();
			break;
		case 2://showlist
			if (total2 == 0) {
				cout << "List is empty!!!\n";
			}
			else {
				cout << setfill('-');
				cout << setw(175) << "-" << endl;
				cout << setfill(' ');
				cout << setw(5) << left << "STT";
				cout << setw(25) << left << "Full Name";
				cout << setw(25) << left << "Date-of-birth";
				cout << setw(25) << left << "School";
				cout << setw(25) << left << "Course";
				cout << setw(10) << left << "Semester";
				cout << setw(10) << left << "Assign_1";
				cout << setw(10) << left << "Assign_2";
				cout << setw(10) << left << "Assign_3";
				cout << setw(10) << left << "Test1";
				cout << setw(10) << left << "Test2";
				cout << setw(10) << left << "Exam";
				cout << endl;
				cout << setfill('-');
				cout << setw(175) << "-" << endl;
				cout << setfill(' ');
				for (int i = 0; i < total2; i++) {
					cout << setw(5) << left << i + 1;
					BK_college[i].display();
				}
				cout << endl;
			}
			pressAnyKey();
			break;
		case 3:// you need to choose this case before you select display
			for (int i = 0; i < total2; i++) {
				BK_college[i].DoAssignment();
			}
			pressAnyKey();
			break;
		case 4:// you need to choose this case before you select display
			for (int i = 0; i < total2; i++) {
				BK_college[i].TakeTest();
			}
			pressAnyKey();
			break;
		case 5:// you need to choose this case before you select display
			for (int i = 0; i < total2; i++) {
				BK_college[i].TakeExam();
			}
			pressAnyKey();
			break;
		default://exit
			break;
		}
	} while (option2 != 6);
}


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
		case 1:
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