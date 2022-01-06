#pragma once
#include "Main_Menu.h"
#include <iostream>
#include <string>
using namespace std;

class Emergency : public Main_Menu
{
private:
	int serial_no;
	string first_name, second_name;
	char f_name[20];
	string gender;
	int age;
	string adm_date;
	string dis_date;
	char emg_type[30];
	char diagnosis[30];
	char treatment[100];
	string doc_fname, doc_sname, file_ext = ".csv";
	//string ext="_emergency";
	int medication_charges;
	int other_charges;
	int total_bill;
protected:
	void SerialNum();
	void Name();
	void FName();
	void Gender();
	void Age();
	void AdmDate();
	void DisDate();
	void EmgType();
	void Diagnosis();
	void Treatment();
	void DocName();
	void TotalBill();
	void menu();
	void FileData();
	void search();
public:
	void print();

};

