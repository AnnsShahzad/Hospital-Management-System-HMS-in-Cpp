#pragma once
#include "Main_Menu.h"
#include <iostream>
#include <string>
using namespace std;

class Doctors_Database : public Main_Menu
{
private:
	int serial_no;
	string first_name, second_name;
	char f_name[20];
	string gender;
	int age;
	char education[30];
	string login_id;
	string login_pass;
	string category;
	int salary;
	char allowances[100];
	string file_ext = ".csv";
protected:
	void SerialNum();
	void Name();
	void fName();
	void Gender();
	void Age();
	void Education();
	void LoginID();
	void LoginPass();
	void Category();
	void search();
	void Salary();
	void Allowances();
	void menu();
	void FileData();
public:
	void print();
};

