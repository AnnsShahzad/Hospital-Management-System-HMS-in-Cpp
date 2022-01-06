// HOSPITAL MANAGEMENT SYSTEM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include "Patient_Database.h"
#include "Patient_Record.h"
#include "Doctors_Database.h"
#include "Staff_Database.h"
#include "Nurses_Database.h"
#include "Emergency.h"
#include "Bed_Database.h"
#include "Attendance_Portal.h"
#include "Pharmacy.h"
#include "Administrator.h"
#include "Main_Menu.h"

void gotoxy(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

void start()
{
	gotoxy(46, 5);
	cout << "------------------\n";
	for (int i = 6; i < 14; i++)
	{
		gotoxy(46, i);
		cout << "|";
	}
	for (int i = 6; i < 14; i++)
	{
		gotoxy(63, i);
		cout << "|";
	}
	gotoxy(46, 14); cout << "------------------\n";

	gotoxy(51, 8);	cout << "HOSPITAL\n";
	gotoxy(49, 10);	cout << "MANAGEMENT\n";
	gotoxy(51, 12);	cout << "SYSTEM\n\n\n";
	gotoxy(14, 18); cout << "-----------------------------------------";
	gotoxy(15, 19);	cout << "PROJECT BY:";
	gotoxy(28, 19);	cout << "ANNS SHAHZAD(2019-CS-601)\n";
	gotoxy(28, 20);	cout << "M.Hassan Ijaz(2019-CS-617)\n";
	gotoxy(28, 21); cout << "Abdul Subhan(2019-CS-646)\n";
	gotoxy(14, 22); cout << "-----------------------------------------";
	gotoxy(13, 18); cout << "|";
	gotoxy(13, 19); cout << "|";
	gotoxy(13, 20); cout << "|";
	gotoxy(13, 21); cout << "|";
	gotoxy(13, 22); cout << "|";
	gotoxy(55, 18); cout << "|";
	gotoxy(55, 19); cout << "|";
	gotoxy(55, 20); cout << "|";
	gotoxy(55, 21); cout << "|";
	gotoxy(55, 22); cout << "|";
	gotoxy(68, 24);	cout << "SUBMITTED TO:";
	gotoxy(82, 24);	cout << "Namra Shiekh\n";
	gotoxy(68, 25);	cout << "-------------------------------\n\n\n";
	gotoxy(101, 25);	_getch();

}




int main()
{
	start();
	Main_Menu mm;			//Initialize object
	mm.print();				//Call the print function of the object
	
	
	return 0;
}

