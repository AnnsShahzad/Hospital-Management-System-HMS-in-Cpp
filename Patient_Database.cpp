#include "Patient_Database.h"
#include <iostream>
#include<string>
#include <conio.h>
#include <fstream>
using namespace std;

void Patient_Database::menu()
{
	//Presntation using ASCII values and other.
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
	cout << "\t3.\tDischarge Slip\t\tD\n";
	cout << "\t4.\tReturn to Main\t\tR\n";
	cout << "\t5.\tExit\t\t\tE\n";
	cout << "\t";
	for (int i = 0; i < 42; i++) //Presntation using ASCII value
		cout << (char(45));
	cout << endl;

	cout << "\n\t\tEnter your option: ";
	char option;
	cin >> option;
	if (option == 'N' || option == 'n')
	{
		system("cls");
		patient_serialNo();
		patient_name();
		patient_fName();
		patient_gender();
		patient_age();
		patient_disease();
		patient_diagnoses();
		patient_medication();
		patient_admit();
		FileData();
		
	}
	if (option == 'D' || option == 'd')
	{
		system("cls");
		patient_serialNo();
		patient_name();
		patient_fName();
		patient_gender();
		patient_age();
		patient_disease();
		patient_diagnoses();
		patient_medication();
		//From Patient record
		AdDate();
		WardNum();
		BedNum();
		TotalDays();
		DaysBills();
		MedicationBill();
		OtherCharges();
		DisDate();
		TotalBill();
		//from patient database
		FileDataDischarge();
		cout << "\n\nPress any key to return Patient Database.";
		_getch();
		menu();
	}
	if (option == 'E' || option == 'e')
		_getch();

	if (option == 'S' || option == 's')
		search();
	if (option == 'R' || option == 'r')
		Menu();

}
void Patient_Database::patient_serialNo()
{
	cout << "Enter Patient Serial No: ";
	cin >> serialNo;
}
void Patient_Database::patient_name()
{
	cout << "Enter Patient Name: ";
	cin >> first_name >> second_name;
	
}
void Patient_Database::patient_fName()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Patient's Father/Husband's Name: ";
	cin.getline(fName, 20);
}
void Patient_Database::patient_gender()
{
	cout << "Enter Patient's Gender: ";
	cin >> gender;
}
void Patient_Database::patient_age()
{
	cout << "Enter Patient's Age: ";
	cin >> age;
}
void Patient_Database::patient_disease()
{
	cin.clear();
	cin.ignore();
	cout << "Enter Name of Disease: ";
	cin.getline(disease, 30);
}
void Patient_Database::patient_diagnoses()
{
	cin.clear();
	cout << "Enter Diagnoses: ";
	cin.getline(diagnoses, 50);
}
void Patient_Database::patient_medication()
{
	cin.clear();
	cout << "Enter Patient's Medication: ";
	cin.getline(medication, 100);
	cin.clear();
}
void Patient_Database::patient_admit()
{
	
	cout << "Admit in Hospital: \n";
	cout << "Yes or No?";
	cin >> admits;
	if (admits == "Yes" || admits == "yes")
	{
		//Patient_Record pt_record;
		AdDate();
		WardNum();
		BedNum();
		cout << "\n\tSuccessfully added!\n\n";
		cout << "\tPress any key to return to Patient Database.\n\n";
		_getch();
		menu();
	}
	if (admits == "No" || admits == "no")
	{
		ofstream f;
		f.open("Patient_Data.csv", ios::app); 
		f << serialNo << "," << first_name << " " << second_name << "," << fName << "," << age
			<< "," << disease << "," << diagnoses << "," << medication << "\n";
		f.close();
		cout << "\nData has successfully added!\n";
		cout << "Press any key to return.";
		_getch();
		menu();
	}
}
void Patient_Database::FileData()
{
	file_type_admit = first_name + file_ext_admit + file_type_admit;
	ofstream f;
	f.open(file_type_admit, ios::app);
	f << "Serial No " << "," << serialNo << "\n"
		<< "Name: " << ","<< first_name << " " << second_name << "\n"
		<< "Father Name: "<<"," << fName << "\n"
		 << "Age: " <<","<< age << "\n"
		 << "Disease: "<<"," << disease << "\n"
		<< "Diagnoses: "<<"," << diagnoses << "\n"
		<< "Medication: " <<","<< medication << "\n"
		<< "Date of Admission: "<<"," << ad_date << "\n"
		<< "Ward No: "<<"," << ward_no << "\n"
		<< "Bed No: "<<"," << bed_no << endl;
	 f.close();
	 file_type_admit = ".csv";
}
void Patient_Database::FileDataDischarge()
{
	file_type_discharge = first_name + file_ext_discharge + file_type_discharge;
	ofstream f;
	f.open(file_type_discharge, ios::app);
	f << "Serial No " << "," << serialNo << "\n"
		<< "Name: " << "," << first_name << " " << second_name << "\n"
		<< "Father Name: " << "," << fName << "\n"
		<< "Age: " << "," << age << "\n"
		<< "Disease: " << "," << disease << "\n"
		<< "Diagnoses: " << "," << diagnoses << "\n"
		<< "Medication: " << "," << medication << "\n"
		<< "Date of Admission: " << "," << ad_date << "\n"
		<< "Ward No: " << "," << int(ward_no) << "\n"
		<< "Bed No: " << "," << int(bed_no) << "\n"
		<< "Total Days: " << "," << total_bill << "\n"
		<< "Days Bill: " << "," << days_bill << "\n"
		<< "Medications Bill: " << "," << medication_bill << "\n"
		<< "Other Charges: " << "," << other_charges << "\n"
		<< "Total Bill: " << "," << total_bill << endl;
	f.close();
	file_type_discharge = ".csv";

}
void Patient_Database::search()
{
	system("cls");
	cout << "Select one of following: \n";
	cout << "Admit\tDischarge\n";
	cin >> Search;
	if (Search == "Admit" || Search == "admit")
	{
		cout << "Enter Paitent's First Name: ";
		cin >> f_first_name;
		file_ext_admit = f_first_name + file_ext_admit + file_type_admit;
		
		ifstream fin;
		fin.open(file_ext_admit);
		string sno, n, fn, a, dis, dia, med, add, diss, wno, bno, td, db, mb, oc, tb;
		string ad, dis_d1, dis_d2, wn1, wn2, bed1, bed2, tt1, tt2, dbill1, dbill2, medb1, medb2, och1, och2, tbill1, tbill2;

		for (int i = 0; fin; i++)
		{
			getline(fin, sno, ',');			getline(fin, n, '\n');
			getline(fin, fn, ',');			getline(fin, a, '\n');
			getline(fin, dis, ',');			getline(fin, med, '\n');
			getline(fin, add, ',');			getline(fin, diss, '\n');
			getline(fin, wno, ',');			getline(fin, bno, '\n');
			getline(fin, td, ',');			getline(fin, db, '\n');
			getline(fin, mb, ',');			getline(fin, oc, '\n');
			getline(fin, tb, ',');			getline(fin, ad, '\n');
			getline(fin, dis_d1, ',');			getline(fin, dis_d2, '\n');
			getline(fin, wn1, ',');			getline(fin, wn2, '\n');
			getline(fin, bed1, ',');			getline(fin, bed2, '\n');
			getline(fin, tt1, ',');			getline(fin, tt2, '\n');
			getline(fin, dbill1, ',');			getline(fin, dbill2, '\n');
			getline(fin, medb1, ',');			getline(fin, medb2, '\n');
			getline(fin, och1, ',');			getline(fin, och2, '\n');
			getline(fin, tbill1, ',');			getline(fin, tbill2, '\n');

			cout << "\n\t"<< sno << ": " << n << endl;			cout << "\t" << fn << ":" << a << endl;
			cout << "\t" << dis << ":" << med << endl;			cout << "\t" << add << ":" << diss << endl;
			cout << "\t" << wno << ":" << bno << endl;			cout << "\t" << tb << ":" << db << endl;
			cout << "\t" << mb << ":" << oc << endl;			cout << "\t" << tb << ":" << ad << endl;
			cout << "\t" << dis_d1 << ":" << dis_d2 << endl;			cout << "\t" << wn1 << ":" << wn2 << endl;
			cout << "\t" << bed1 << ":" << bed2 << endl;			cout << "\t" << tt1 << ":" << tt2 << endl;
			cout << "\t" << dbill1 << ":" << dbill2 << endl;			cout << "\t" << medb1 << ":" << medb2 << endl;
			cout << "\t" << och1 << ":" << och2 << endl;			cout << "\t" << tbill1 << ":" << tbill2 << endl;
		}
		fin.close();
		_getch();
		menu();
		
	}
	if (Search == "Discharge" || Search == "discharge")
	{
		cout << "Enter Paitent's First Name: ";
		cin >> f_first_name;
		file_ext_discharge = f_first_name + file_ext_discharge + file_type_discharge;

		ifstream f_discharge;
		f_discharge.open(file_ext_discharge);
		string sno, n, fn, a, dis, dia, med, add, diss, wno, bno, td, db, mb, oc, tb;
		string ad, dis_d1, dis_d2, wn1, wn2, bed1, bed2, tt1, tt2, dbill1, dbill2, medb1, medb2, och1, och2, tbill1, tbill2;

		for (int i = 0; f_discharge; i++)
		{
			getline(f_discharge, sno, ',');			getline(f_discharge, n, '\n');
			getline(f_discharge, fn, ',');			getline(f_discharge, a, '\n');
			getline(f_discharge, dis, ',');			getline(f_discharge, med, '\n');
			getline(f_discharge, add, ',');			getline(f_discharge, diss, '\n');
			getline(f_discharge, wno, ',');			getline(f_discharge, bno, '\n');
			getline(f_discharge, td, ',');			getline(f_discharge, db, '\n');
			getline(f_discharge, mb, ',');			getline(f_discharge, oc, '\n');
			getline(f_discharge, tb, ',');			getline(f_discharge, ad, '\n');
			getline(f_discharge, dis_d1, ',');			getline(f_discharge, dis_d2, '\n');
			getline(f_discharge, wn1, ',');			getline(f_discharge, wn2, '\n');
			getline(f_discharge, bed1, ',');			getline(f_discharge, bed2, '\n');
			getline(f_discharge, tt1, ',');			getline(f_discharge, tt2, '\n');
			getline(f_discharge, dbill1, ',');			getline(f_discharge, dbill2, '\n');
			getline(f_discharge, medb1, ',');			getline(f_discharge, medb2, '\n');
			getline(f_discharge, och1, ',');			getline(f_discharge, och2, '\n');
			getline(f_discharge, tbill1, ',');			getline(f_discharge, tbill2, '\n');
			
			cout << "\n\t"<< sno << ": " << n << endl;			cout << "\t" << fn << ":" << a << endl;
			cout << "\t" << dis << ":" << med << endl;			cout << "\t" << add << ":" << diss << endl;
			cout << "\t" << wno << ":" << bno << endl;			cout << "\t" << tb << ":" << db << endl;
			cout << "\t" << mb << ":" << oc << endl;			cout << "\t" << tb << ":" << ad << endl;
			cout << "\t" << dis_d1 << ":" << dis_d2 << endl;			cout << "\t" << wn1 << ":" << wn2 << endl;
			cout << "\t" << bed1 << ":" << bed2 << endl;			cout << "\t" << tt1 << ":" << tt2 << endl;
			cout << "\t" << dbill1 << ":" << dbill2 << endl;			cout << "\t" << medb1 << ":" << medb2 << endl;
			cout << "\t" << och1 << ":" << och2 << endl;			cout << "\t" << tbill1 << ":" << tbill2 << endl;
		}
		f_discharge.close();
		_getch();
		menu();
	}
	
}

void Patient_Database::print()
{
	menu();

}