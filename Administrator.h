#pragma once
#include "Main_Menu.h"
#include <iostream>
#include <string>
using namespace std;

class Administrator : public Main_Menu
{
private:
	string id, password;
	string Admin_id, first_name, second_name;
	string f_name, s_name;
	int pass;
	string login_id, login_pass;
protected:
	void Name();
	void LoginID();
	void LoginPass();
	void menu();
public:
	void print();
};

