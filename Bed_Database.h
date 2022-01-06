#pragma once
#include "Main_Menu.h"
#include <iostream>
#include <string>
using namespace std;

class Bed_Database : public Main_Menu
{
private:
	int total_beds=1000;
	int total_patients;
	int occupied_beds;
	int damaged_beds;
	int remaining_beds;
protected:
	void TotalPatients();
	void OccupiedBeds();
	void DamagedBeds();
	void RemainingBeds();
public:
	void print();
};

