#pragma once
#include "Virus.h"
#include <list>

class Fluvirus : public Virus
{
public:
	Fluvirus();
	~Fluvirus();

	void DoBorn();
	std::list<Virus*> Fluvirus::DoClone();
	void DoDie();
	void InitResistance();
private:
	unsigned int m_color;
	
};

