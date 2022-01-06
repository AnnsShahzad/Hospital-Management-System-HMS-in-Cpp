#include "Main_Menu.h"
#include "Patient_Database.h"
#include "Patient_Record.h"
#include "Doctors_Database.h"
#include "Staff_Database.h"
#include "Nurses_Database.h"
#include "Emergency.h"
#include "Bed_Database.h"
#include "Attendance_Portal.h"
#include "Pharmacy.h"
#include "Administrator.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
using namespace std;


void Main_Menu::Menu()
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
	for (int i = 0; i < 43; i++)
		cout << (char(45));
	cout << endl;
	cout << "\tSr.\tDescription\t\tPress Key\n";
	cout << "\t";
	for (int i = 0; i < 43; i++)
		cout << (char(45));
	cout << endl;
	cout << "\t1.\tPatient Database\t1\n";
	cout << "\t2.\tDoctor Database\t\t2\n";
	cout << "\t3.\tStaff Database\t\t3\n";
	cout << "\t4.\tNurses Database\t\t4\n";
	cout << "\t5.\tEmergency\t\t5\n";
	cout << "\t6.\tBed Database\t\t6\n";
	cout << "\t7.\tAttendance\t\t7\n";
	cout << "\t8.\tPharmacy\t\t8\n";
	cout << "\t9.\tAdministration\t\t9\n";
	cout << "\t10.\tQuit\t\t\t0\n";
	cout << "\t";
	for (int i = 0; i < 43; i++)
		cout << (char(45));
	cout << endl;

	cout << "\n\t\tSelect your Option: ";
	int option;
	cin >> option;

	Patient_Database pd; Doctors_Database dd; Staff_Database sd; Nurses_Database nd;
	Emergency e; Bed_Database bd; Attendance_Portal ap; Pharmacy p; Administrator a;

	if (option == 1)
		pd.print();
	if (option == 2)
		dd.print();
	if (option == 3)
		sd.print();
	if (option == 4)
		nd.print();
	if (option == 5)
		e.print();
	if (option == 6)
		bd.print();
	if (option == 7)
		ap.print();
	if (option == 8)
		p.print();
	if (option == 9)
		a.print();
	if (option == 0) {
		system("exit");
	}


}
void Main_Menu::print()
{
		/*system("cls");
		cout << "\n\n\n\n\n\n\n\t\t\t\tEnter Admin Id: ";
		string id;
		cin >> id;
		ifstream f;
		f.open("Admin.txt");
		string a, b, c, d;
		getline(f, a, ',');
		getline(f, b, ',');
		getline(f, c, ',');
		getline(f, d, '\n');
		if (id == c)
		{
			cout << "\t\t\t\tEnter Admin Password: ";
			string pass;
			cin >> pass;
			if (pass == d)
			{
				Menu();
			}
			else
				cout << "\n\t\t\t\tInvalid Input!\n\n";
		}
		else
			cout << "\n\t\t\t\tInvalid Input!\n\n";
			*/
	Menu();
}