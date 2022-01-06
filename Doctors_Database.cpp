#include "Doctors_Database.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;

void Doctors_Database::menu()
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
	cout << "\t1.\tAdd New Doctor\t\tN\n";
	cout << "\t2.\tSearch Doctor\t\tS\n";
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
		fName();
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

void Doctors_Database::SerialNum()
{
	cout << "Enter Serial No: ";
	cin >> serial_no;
}
void Doctors_Database::Name()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Name of Doctor: ";
	cin >> first_name >> second_name;
}
void Doctors_Database::fName()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Father's/Husband's Name: ";
	cin.getline(f_name,20);
}
void Doctors_Database::Gender()
{
	cout << "Enter the Gender: ";
	cin >> gender;
}
void Doctors_Database::Age()
{
	cout << "Enter Age of Doctor: ";
	cin >> age;
}
void Doctors_Database::Education()
{
	cin.clear();
	cin.ignore();
	cout << "Enter the Education: ";
	cin.getline(education, 30);
}
void Doctors_Database::LoginID()
{
	string dot = ".";
	login_id = "@hospital.pk";
	cout << "\nYour Login ID is: ";

	login_id = first_name + dot + category + login_id;
	cout << login_id << endl;

}
void Doctors_Database::LoginPass()
{
	srand(time(NULL));
	int pass = (rand()*12);
	login_pass = "*&";
	cout << "Your Password is: ";

	login_pass = category + login_pass + second_name;
	cout << login_pass << pass << endl;

	ofstream f_pass;
	f_pass.open("ID Data.csv", ios::app);
	f_pass << first_name << " " << second_name << "," << login_id << "," << login_pass << pass << "\n";
	f_pass.close();
	cout << "\n\tSuccessfully Added!\n";

}
void Doctors_Database::Category()
{
	cout << "Select the Category: \n";
	cout << "Doctor\t\tSurgeon\t\tResearcher" << endl;
	cin >> category;
}
void Doctors_Database::Salary()
{
	cout << "Enter the Salary(in PKR): ";
	cin >> salary;
}
void Doctors_Database::Allowances()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Allowances(if any): ";
	cin.getline(allowances, 100);
}

void Doctors_Database::FileData()
{
	file_ext = first_name+ file_ext;
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
	cout << "\nPress any key to return.";
	_getch();
	menu();

}
void Doctors_Database::search()
{
	cout << "Enter Doctor's First Name: ";
	string data_search;
	cin >> data_search;

	string s_name = data_search;
	data_search = data_search + file_ext;

	ifstream fout;
	fout.open(data_search);
	for (int i = 0; i<1; i++)
	{
		string a, b, c, d, e, g, h, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

		getline(fout, a, ',');		getline(fout, b, '\n');
		getline(fout, c, ',');		getline(fout, d, '\n');
		getline(fout, e,',');		getline(fout, v, '\n');
		getline(fout, g, ',');		getline(fout, h, '\n');
		getline(fout, u, ',');		getline(fout, j, '\n');
		getline(fout, k, ',');		getline(fout, l, '\n');
		getline(fout, m, ',');		getline(fout, n, '\n');
		getline(fout, o, ',');		getline(fout, p, '\n');
		getline(fout, q, ',');		getline(fout, r, '\n');
		getline(fout, s, ',');		getline(fout, t, '\n');
		getline(fout, w, ',');		getline(fout, x, '\n');
		fout.close();

		ifstream f_comp;
		string comp_name, comp_id, comp_pass;
		f_comp.open("ID Data.csv");
		string check=" ";
		
		for (int i = 0; f_comp; i++)
		{
			getline(f_comp, comp_name, ',');
			getline(f_comp, comp_id, ',');
			getline(f_comp, comp_pass, '\n');
			if (check != comp_name)
			{
				if (d == comp_name)
				{
					cout << "\nDOCTOR'S DATA: \n";
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
			}
			else
			{
				cout << "Invalid!";
			}
			check = comp_name;
		}
		f_comp.close();

	}
	fout.close();
	cout << "\n\n\n\n\nPress any key to return.";
	_getch();
	menu();
}


void Doctors_Database::print()
{
	menu();
}