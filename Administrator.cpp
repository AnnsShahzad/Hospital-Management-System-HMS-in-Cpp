#include "Administrator.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <conio.h>
using namespace std;

void Administrator::menu()
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
	cout << "\t1.\tChange ID/Pass\t\tN\n";
	cout << "\t2.\tReturn to Main\t\tR\n";
	cout << "\t3.\tExit\t\t\tE\n";
	cout << "\t";
	for (int i = 0; i < 42; i++)
		cout << (char(45));
	cout << endl;

	cout << "\n\t\tEnter your option: ";
	char option;
	cin >> option;
	if (option == 'N' || option == 'n')
	{
		system("cls");
		Name();
	}
	if (option == 'R' || option == 'r')
		Menu();
	if (option == 'E' || option == 'e')
		_getch();

}
void Administrator::Name()
{
	cout << "Enter Admin's First Name: ";
	cin >> f_name;
	ifstream ff;
	ff.open("Admin.txt");
	string fn, sn, e, p;

	getline(ff, fn, ',');
	getline(ff, sn, ',');
	getline(ff, e, ',');
	getline(ff, p, '\n');

	if (fn == f_name)
	{
		cout << "Enter Admin's Second Name: ";
		cin >> s_name;
		if (sn == s_name)
		{
			cout << "Enter Admin's ID: ";
			cin >> id;
			if (id == e)
			{
				cout << "Enter Admin's Password: ";
				cin >> password;
				if (password == p)
				{
					cout << "\nEnter New Admin's First Name: ";
					cin >> first_name;
					cout << "Enter New Admin's Second Name: ";
					cin >> second_name;
					LoginID();
					LoginPass();
				}
				else
					cout << "Invalid Input!\n";
			}
			else
				cout << "Invalid Input!\n";
		}
		else
			cout << "Invalid Input!\n";
	}
	else
		cout << "Invalid Input!\n";

}

void Administrator::LoginID()
{
	ofstream fff;
	fff.open("Admin.txt");
	fff << first_name << "," << second_name << ",";

	cout << "\nYour New Login ID is: ";
	login_id = ".admin@hospital.pk";

	login_id = first_name + login_id;
	cout << login_id << endl;


	fff << login_id << "," << password << endl;
	fff.close();
}
void Administrator::LoginPass()
{
	ofstream f;
	f.open("Admin.txt");
	f << first_name << "," << second_name << "," << login_id << ",";

	cout << "Your New Login Password is: ";
	srand(time(NULL));
	pass = (rand()*12);
	login_pass = "*&";

	login_pass = second_name + login_pass;
	cout << login_pass << pass << endl;

	f << login_pass << pass << endl;
	f.close();
}


void Administrator::print()
{
	menu();
}