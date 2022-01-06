#pragma once
//#include "Patient_Database.h"
#include <iostream>
#include <string>
using namespace std;
class Patient_Record 
{
private:
	int serial_no;
protected:
	string ad_date;
	string dis_date;
	int ward_no;
	int bed_no;
	int total_days;
	int days_bill;
	int medication_bill;
	int other_charges;
	int total_bill;

	void SerialNo();
	void AdDate();
	void DisDate();
	void WardNum();
	void BedNum();
	void TotalDays();
	void DaysBills();
	void MedicationBill();
	void OtherCharges();
	void TotalBill();
	//void menu();
public:
	void discharge();
	void print();
};

