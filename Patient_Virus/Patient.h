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
	std::list<Virus*> m_virusList;
private:
	int m_resistance;
	int m_state;
};

