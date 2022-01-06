#include "Attendance_Portal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

void Attendance_Portal::menu()
{
	system("cls");
	cout << "\t\t    ";
	for (int i = 0; i < 35; i++)
		cout << (char(45));
	cout << endl;
	cout << "\t\t\tHOSPITAL MANAGEMENT SYSTEM\n";
	cout << "\t\t    ";
	for (int i = 0; i < 35; i++)
		cout << (char(45));

	cout << "\n\n\t";
	for (int i = 0; i < 42; i++)
		cout << (char(45));
	cout << endl;
	cout << "\tSr.\tDescription\t\tPress Key\n";
	cout << "\t";
	for (int i = 0; i < 42; i++)
		cout << (char(45));
	cout << endl;
	cout << "\t1.\tMark Attendance\t\tA\n";
	cout << "\t2.\tCheck your Attendance\tC\n";
	cout << "\t3.\tReturn to Main\t\tR\n";
	cout << "\t4.\tExit\t\t\tE\n";
	cout << "\t";
	for (int i = 0; i < 42; i++)
		cout << (char(45));
	cout << endl;

	cout << "\n\t\tEnter your option: ";
	char option;
	cin >> option;

	if (option == 'A' || option == 'a')
		MarkAttendance();
	if (option == 'C' || option == 'c')
		CheckAttendance();
	if (option == 'R' || option == 'r')
		Menu();
	if (option == 'E' || option == 'e')
		_getch();
}

void Attendance_Portal::LoginID()
{
	cout << "Enter Login ID: ";
	cin >> login_id;
}
void Attendance_Portal::LoginPass()
{
	cout << "Enter Login Password: ";
	cin >> login_pass;
}
void Attendance_Portal::MarkAttendance()
{
	LoginID();
	LoginPass();
	ifstream f_check;
	f_check.open("ID Data.csv");
	string name, email, pass;

	for (int i = 0; f_check; i++)
	{
		getline(f_check, name, ',');
		getline(f_check, email, ',');
		getline(f_check, pass, '\n');
		if (email == login_id && pass==login_pass)
		{
			cout << "\nPress \"P\"to mark your Attendance" << endl;
			cin >> mark_attendance;
			if (mark_attendance == "P" || mark_attendance == "p")
			{
				ofstream f_mark;
				f_mark.open("Attendance.csv");
				f_mark << name << "," << email << "," << "P" << endl;
				f_mark.close();
				cout << "\n\tAttendance Marked!\n";
				cout << "Press any key to return.";
				_getch();
				menu();
			}
		}
	}
	f_check.close();
}

void Attendance_Portal::CheckAttendance()
{
	LoginID();
	LoginPass();

	ifstream f_check;
	f_check.open("ID Data.csv");
	string name, email, pass, check, check1;
	int counter = 0;

	for (int i = 0; f_check; i++)
	{
		getline(f_check, name, ',');
		getline(f_check, email, ',');
		getline(f_check, pass, '\n');
		if (check != email)
		{
			if (login_id == email && login_pass == pass)
			{
				ifstream f_attendance;
				f_attendance.open("Attendance.csv");
				string name1, email1, status;
				for (int i = 0; f_attendance; i++)
				{
					getline(f_attendance, name1, ',');
					getline(f_attendance, email1, ',');
					getline(f_attendance, status, '\n');
					if (status == "P" || status == "p")
					{
						counter++;
						if (counter > 29)
							break;
					}
					if (check1 == email1)
					{
						counter--;
						break;
					}
					check1 = email1;
				}

				cout << "Your Total Attendance = " << counter << "/30" << endl;
			}
		}
		check = email;
	}


}

void Attendance_Portal::print()
{
	menu();
}