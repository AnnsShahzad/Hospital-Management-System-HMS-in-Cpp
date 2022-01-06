#pragma once
#include "Main_Menu.h"
#include <iostream>
#include <string>
using namespace std;

class Nurses_Database : public Main_Menu
{
private:
	int serial_no;
	string first_name, second_name;
	char f_name[20];
	string gender;
	int age;
	char education[30];
	string category;
	string login_id;
	string login_pass;
	int salary;
	char allowances[100];
	string file_ext = ".csv";
protected:
	void SerialNum();
	void Name();
	void FName();
	void Gender();
	void Age();
	void Education();
	void Category();
	void LoginID();
	void LoginPass();
	void Salary();
	void Allowances();
	void menu();
	void FileData();
	void search();
public:
	void print();

};

