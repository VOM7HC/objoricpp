#include <list>
#include "Virus.h"
#include <cstdlib>
#pragma once
class Patient
{
public:
	Patient();
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int medicine_resistance);
	void DoDie();
	int GetState();
private:
	int m_resistance;
	std::list<Virus*> m_virusList;
	int m_state;
};

