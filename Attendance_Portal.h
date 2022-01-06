#pragma once
#include "Main_Menu.h"
#include <iostream>
#include <string>
using namespace std;

class Attendance_Portal : public Main_Menu
{
private:
	string login_id;
	string login_pass;
	string mark_attendance;
	int total_doc;
	int total_staff;
	int total_nurses;
	int total_admins;
protected:
	void LoginID();
	void LoginPass();
	void MarkAttendance();
	void CheckAttendance();
	void menu();
public:
	void print();
};

