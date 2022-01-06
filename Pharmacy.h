#pragma once
#include "Main_Menu.h"
#include <iostream>
#include <string>
using namespace std;

class Pharmacy : public Main_Menu
{
private:
	int serial_no;
	string customer_fname;
	string med_name;
	string company_name;
	string category;
	string date;
	string Search;
	string order;
	int quantity;
	int price;
	int total_bill;
protected:
	void SerialNum();
	void CustomerName();
	void MedName();
	void CompanyName();
	void Category();
	void Date();
	void Quantity();
	void Price();
	void TotalBill();
	void menu();
	void FileData();
	void search();
public:
	void print();
};

