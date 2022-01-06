#include "Staff_Database.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <conio.h>
using namespace std;

void Staff_Database::menu()
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
	cout << "\t1.\tAdd New Staff\t\tN\n";
	cout << "\t2.\tSearch Staff\t\tS\n";
	cout << "\t3.\tReturn to Main\t\tR\n";
	cout << "\t4.\tExit\t\t\tE\n";
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
		SerialNum();
		Name();
		FName();
		Gender();
		Age();
		Education();
		Category();
		Salary();
		Allowances();
		LoginID();
		LoginPass();
		FileData();

	}
	if (option == 'S' || option == 's')
	{
		system("cls");
		search();
	}
	if (option == 'R' || option == 'r')
		Menu();
	if (option == 'E' || option == 'e')
		_getch();

}
void Staff_Database::SerialNum()
{
	cout << "Enter Serial No: ";
	cin >> serial_no;
}
void Staff_Database::Name()
{
	cout << "Enter the Name: ";
	cin >> first_name >> second_name;
}
void Staff_Database::FName()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Father's/Husaband's Name: ";
	cin.getline(f_name, 20);
}
void Staff_Database::Gender()
{
	cout << "Enter the Gender: ";
	cin >> gender;
}
void Staff_Database::Age()
{
	cout << "Enter the Age: ";
	cin >> age;
}
void Staff_Database::Education()
{
	cin.clear();
	cin.ignore();
	cout << "Enter the Education: ";
	cin.getline(education, 30);
}
void Staff_Database::Category()
{
	cout << "Select the Category: \n";
	cout << "Maid\tSweeper\t\tGardener\tGuard\n";
	cin >> category;
}
void Staff_Database::LoginID()
{
	login_id = ".staff@hospital.pk";
	cout << "\nYour Login ID is: ";

	login_id = first_name + login_id;
	cout << login_id << endl;
}
void Staff_Database::LoginPass()
{
	srand(time(NULL));
	int pass = (rand() * 12);
	login_pass = "*&";
	cout << "Your Login Password is: ";

	login_pass = category + login_pass + second_name;
	cout << login_pass << pass << endl;

	ofstream f_pass;
	f_pass.open("ID Data.csv", ios::app);
	f_pass << first_name << " " << second_name << "," << login_id << "," << login_pass << pass << "\n";
	f_pass.close();
}
void Staff_Database::Salary()
{
	cout << "Enter the Salary: ";
	cin >> salary;
}
void Staff_Database::Allowances()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Allowances(if any): ";
	cin.getline(allowances, 100);
}
void Staff_Database::FileData()
{
	file_ext = first_name + file_ext;
	ofstream f;
	f.open(file_ext);
	f << "Serial No" << "," << serial_no << "\n"
		<< "Name" << "," << first_name << " " << second_name << "\n"
		<< "Father's Name" << "," << f_name << "\n"
		<< "Gender" << "," << gender << "\n"
		<< "Age " << "," << age << "\n"
		<< "Education " << "," << education << "\n"
		<< "Category" << "," << category << "\n"
		<< "Salary " << "," << salary << "\n"
		<< "Allowances " << "," << allowances << "\n"
		<< "Login ID" << "," << login_id << "\n"
		<< "Login Password" << "," << login_pass << "\n";
	f.close();
}
void Staff_Database::search()
{
	cout << "Enter Staff's First Name: ";
	string data_search;
	cin >> data_search;
	data_search = data_search + file_ext;
	ifstream fout;
	fout.open(data_search);
	for (int i = 0; i < 1; i++)
	{
		string a, b, c, d, e, g, h, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

		getline(fout, a, ',');		getline(fout, b, '\n');
		getline(fout, c, ',');		getline(fout, d, '\n');
		getline(fout, e, ',');		getline(fout, v, '\n');
		getline(fout, g, ',');		getline(fout, h, '\n');
		getline(fout, u, ',');		getline(fout, j, '\n');
		getline(fout, k, ',');		getline(fout, l, '\n');
		getline(fout, m, ',');		getline(fout, n, '\n');
		getline(fout, o, ',');		getline(fout, p, '\n');
		getline(fout, q, ',');		getline(fout, r, '\n');
		getline(fout, s, ',');		getline(fout, t, '\n');
		getline(fout, w, ',');		getline(fout, x, '\n');

		cout << "\nSTAFF'S DATA: \n";
		cout << "\n\t" << a << ": \t\t" << b << endl;
		cout << "\t" << c << ": \t\t\t" << d << endl;
		cout << "\t" << e << ": \t\t" << v << endl;
		cout << "\t" << g << ": \t\t" << h << endl;
		cout << "\t" << u << ": \t\t\t" << j << endl;
		cout << "\t" << k << ": \t\t" << l << endl;
		cout << "\t" << m << ": \t\t" << n << endl;
		cout << "\t" << o << ": \t\t" << p << endl;
		cout << "\t" << q << ": \t\t" << r << endl;
		cout << "\t" << s << ": \t\t" << t << endl;
		cout << "\t" << w << ": \t" << x << endl;
	}
	fout.close();
	cout << "\n\n\n\n\nPress any key to return.";
	
	_getch();
	menu();
}

void Staff_Database::print()
{
	menu();
}