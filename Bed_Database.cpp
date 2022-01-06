#include "Bed_Database.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void Bed_Database::TotalPatients()
{
	cout << "Enter total patients: ";
	cin >> total_patients;
}
void Bed_Database::OccupiedBeds()
{
	occupied_beds = total_patients;
}
void Bed_Database::DamagedBeds()
{
	cout << "Enter no of Damaged Beds: ";
	cin >> damaged_beds;
}
void Bed_Database::RemainingBeds()
{
	remaining_beds = total_beds - (occupied_beds + damaged_beds);
	cout << "\nTotal Beds: " << total_beds << endl;
	cout << "Occupied Beds: " << occupied_beds << endl;
	cout << "Damaged Beds: " << damaged_beds << endl;
	cout << "Remaining Beds: " << remaining_beds << endl;

	cout << "Press any key to return.\n";
	_getch();
	Menu();
}
void Bed_Database::print()
{
	TotalPatients();
	DamagedBeds();
	OccupiedBeds();
	RemainingBeds();
}