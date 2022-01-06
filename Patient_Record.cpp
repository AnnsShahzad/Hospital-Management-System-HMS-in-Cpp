#include "Patient_Record.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

void Patient_Record::SerialNo()
{
	cout << "Enter Serial No: ";
	cin >> serial_no;
}
void Patient_Record::AdDate()
{
	cout << "Date of Admission(DD/MM/YYYY): ";
	cin >> ad_date;
}
void Patient_Record::DisDate()
{
	cout << "Date of Discharge(DD/MM/YYYY): ";
	cin >> dis_date;
}
void Patient_Record::WardNum()
{
	cout << "Enter Ward No: ";
	cin >> ward_no;
}
void Patient_Record::BedNum()
{
	cout << "Enter Bed No: ";
	cin >> bed_no;
}
void Patient_Record::TotalDays()
{
	cout << "Enter no. of days: ";
	cin >> total_days;
}
void Patient_Record::DaysBills()
{
	days_bill = 0;
	cout << "\nPer Day Dues = PKR.1000\n";
	cout << "Bed Bill: ";
	days_bill = total_days * 1000;
	cout << total_days << "x1000 = PKR." << days_bill << endl;
}
void Patient_Record::MedicationBill()
{
	medication_bill = 0;
	cout << "\nEnter Medication Bills: ";
	cin >> medication_bill;
}
void Patient_Record::OtherCharges()
{
	other_charges = 0;
	cout << "Enter Other Charges: ";
	cin >> other_charges;
}
void Patient_Record::TotalBill()
{
	cout << "\nTotal Bill: \n";
	total_bill = 0;
	total_bill = days_bill + medication_bill + other_charges;
	cout << days_bill << " x " << medication_bill << " x " << other_charges
		<< " = PKR." << total_bill << endl;
}
void Patient_Record::discharge()
{
	
}

void Patient_Record::print()
{

}