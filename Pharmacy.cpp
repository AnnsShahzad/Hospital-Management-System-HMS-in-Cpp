#include "Pharmacy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

void Pharmacy::menu()
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
	cout << "\t1.\tAdd New Medicine\t\tN\n";
	cout << "\t2.\tSearch Medicine\t\tS\n";
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
		MedName();
		Category();
		CompanyName();
		Quantity();
		Price();
		FileData();
	}
	if (option == 'S' || option == 's')
		search();
	if (option == 'R' || option == 'r')
		Menu();
	if (option == 'E' || option == 'e')
		_getch();

}
void Pharmacy::SerialNum()
{
	cout << "Enter Serial No: ";
	cin >> serial_no;
}
void Pharmacy::CustomerName()
{
	cout << "Enter Customer's First Name: ";
	cin >> customer_fname;
}
void Pharmacy::MedName()
{
	cout << "Enter Name of Medicine: ";
	cin >> med_name;
}
void Pharmacy::CompanyName()
{
	cout << "Enter Company's Name: ";
	cin >> company_name;
}
void Pharmacy::Category()
{
	cout << "Enter Category of Medicine: ";
	cin >> category;
}
void Pharmacy::Date()
{
	cout << "Enter Date(DD/MM/YYYY): ";
	cin >> date;
}
void Pharmacy::Quantity()
{
	cout << "Enter the Quantity: ";
	cin >> quantity;
}
void Pharmacy::Price()
{
	cout << "Enter Price of Medicine: ";
	cin >> price;
}
void Pharmacy::TotalBill()
{
	ifstream f_bill;
	f_bill.open("Pharmacy.csv");
	string data1, data2, data3, data4, data5, data6;
	for (int i = 0; f_bill; i++)
	{
		getline(f_bill, data1, ',');
		getline(f_bill, data2, ',');
		getline(f_bill, data3, ',');
		getline(f_bill, data4, ',');
		getline(f_bill, data5, ',');
		getline(f_bill, data6, '\n');
		if (Search == data2)
		{
			int int_price;
			int_price = stoi(data6);
			total_bill = int_price * quantity;
			cout << "Total Bill = Rs." << total_bill << endl;
		}
	}

}
void Pharmacy::FileData()
{
	ofstream f_phar;
	f_phar.open("Pharmacy.csv");
	f_phar << serial_no << "," << med_name << "," << category << "," << company_name << ","
		<< quantity << "," << price << "\n";
	f_phar.close();

	cout << "\n\tSuccessfully added!\n";
	cout << "Press any key to Return\n";
	_getch();
	menu();
}
void Pharmacy::search()
{
	cout << "Enter name of Medicine: ";
	cin >> Search;

	ifstream f_search;
	f_search.open("Pharmacy.csv");
	string sno, mn, c, cn, q, p;
	for (int i = 0; f_search; i++)
	{
		getline(f_search, sno, ',');
		getline(f_search, mn, ',');
		getline(f_search, c, ',');
		getline(f_search, cn, ',');
		getline(f_search, q, ',');
		getline(f_search, p, '\n');

		if (mn == Search)
		{
			cout << sno << "\t" << mn << "\t" << c << "\t" << cn << "\t" << q << "\t" << p << endl;
			cout << "\nOrder(Y/N)?";
			cin >> order;
			if (order == "Y" || order == "y")
			{
				Quantity();
				TotalBill();
				cout << "\nPress any key to return.";
				_getch();
				menu();
			}
			if (order == "N" || order == "n")
			{
				cout << "\nPress any key to return.";
				_getch();
				menu();
			}
		}
	}
	f_search.close();
}

void Pharmacy::print()
{
	menu();
}