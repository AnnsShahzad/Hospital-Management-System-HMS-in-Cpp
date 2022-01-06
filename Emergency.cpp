#include "Emergency.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

void Emergency::menu()
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
	cout << "\t1.\tAdd New Patient\t\tN\n";
	cout << "\t2.\tSearch Patient\t\tS\n";
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
		AdmDate();
		EmgType();
		Diagnosis();
		Treatment();
		DisDate();
		DocName();
		TotalBill();
		FileData();
	}
	if (option == 'S' || option == 's')
		search();
	if (option == 'R' || option == 'r')
		Menu();
	if (option == 'E' || option == 'e')
		_getch();

}
void Emergency::SerialNum()
{
	cout << "Enter the Serial No: ";
	cin >> serial_no;
}
void Emergency::Name()
{
	cout << "Enter Patient's Name: ";
	cin >> first_name >> second_name;
}
void Emergency::FName()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Father's/Husband's Name: ";
	cin.getline(f_name, 20);
}
void Emergency::Gender()
{
	cout << "Enter the Gender: ";
	cin >> gender;
}
void Emergency::Age()
{
	cout << "Enter Patient's Age: ";
	cin >> age;
}
void Emergency::AdmDate()
{
	cout << "Enter Date of Admission: ";
	cin >> adm_date;
}
void Emergency::DisDate()
{
	cout << "Enter Date of Discharge: ";
	cin >> dis_date;
}
void Emergency::EmgType()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Type of Emergency: ";
	cin.getline(emg_type, 30);
}
void Emergency::Diagnosis()
{
	cout << "Enter the Diagnosis: ";
	cin.getline(diagnosis, 50);
}
void Emergency::Treatment()
{
	cout << "Enter the Treatment: ";
	cin.getline(treatment, 100);
}
void Emergency::DocName()
{
	cout << "Enter Doctor's Name: ";
	cin >> doc_fname >> doc_sname;
}
void Emergency::TotalBill()
{
	cout << "Enter Medication charges: ";
	cin >> medication_charges;
	cout << "Enter Other charges: ";
	cin >> other_charges;
	cout << "\nTotal Bill: \n";
	total_bill = medication_charges + other_charges;
	cout << medication_charges << "+" << other_charges << " = " << total_bill << endl;

}
void Emergency::FileData()
{
	file_ext = first_name + file_ext;
	ofstream f;
	f.open(file_ext, ios::app);
	f << "Serial No " << "," << serial_no << "\n"
		<< "Name: " << "," << first_name << " " << second_name << "\n"
		<< "Father Name: " << "," << f_name << "\n"
		<< "Age: " << "," << age << "\n"
		<< "Type of Emergency: " << "," << emg_type << "\n"
		<< "Date of Admission: " << "," << adm_date << "\n"
		<< "Diagnosis: " << "," << diagnosis << "\n"
		<< "Treatment: " << "," << treatment << "\n"
		<< "Date of Discharge: " << "," << dis_date << "\n"
		<< "Name of Doctor:" << "," << doc_fname << " " << doc_sname << "\n"
		<< "Total Bill: " << "," << total_bill << endl;
	f.close();

	cout << "Press any key to return.\n";
	_getch();
	menu();

}

void Emergency::search()
{
	cout << "Enter Patient's First Name: ";
	string data_search;
	cin >> data_search;
	data_search = data_search  + file_ext;		
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

		cout << "\nPATIENT'S DATA: \n";
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
void Emergency::print()
{
	menu();
}