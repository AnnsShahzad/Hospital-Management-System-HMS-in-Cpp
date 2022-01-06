#pragma once
#include "Main_Menu.h"
#include "Patient_Record.h"
#include <iostream>
#include <string>
using namespace std;

class Patient_Database : public Patient_Record , public Main_Menu
{
private:
	int serialNo;
	string file_type_admit=".csv";
	string file_type_discharge = ".csv";
	string file_ext_admit = "_admit";
	string file_ext_discharge = "_discharge";
	string first_name, second_name, f_first_name;
	char fName[20];
	string gender;
	int age;
	char disease[30];
	char diagnoses[50];
	int admit;
	string admits;
	string Search;
	char medication[100];

protected:
	void patient_serialNo();
	void patient_name();
	void patient_fName();
	void patient_gender();
	void patient_age();
	void patient_disease();
	void patient_diagnoses();
	void patient_medication();
	void patient_admit();
	void search();
	void FileData();
	void FileDataDischarge();
	void menu();
public:
	void print();
	
};

