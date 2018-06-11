#include "stdafx.h"
#include "Fluvirus.h"


Fluvirus::Fluvirus()
{
	InitResistance();
	DoBorn();
}

Fluvirus::~Fluvirus()
{
	DoDie();
}

void Fluvirus::DoBorn()
{
	LoadADNInformation();
	if (rand() % 2 == 0)
		this->m_color = 255;
	else
		this->m_color = 16711680;
}

std::list<Virus*> Fluvirus::DoClone()
{
	Fluvirus *other = new Fluvirus;
	std::list<Virus*> tempLst;

	other->m_color = this->m_color;
	other->m_dna = this->m_dna;
	other->m_resistance = this->m_resistance;

	tempLst.push_back(other);
	
	other = NULL;
	delete other;

	return tempLst;
	tempLst.clear();
}

void Fluvirus::DoDie()
{
	//this->m_dna = NULL;
	//this->m_color = NULL;
	//this->m_resistance = NULL;

	delete this;
}

void Fluvirus::InitResistance()
{
	if (this->m_color == 255)
	{
		m_resistance = 10 + (rand() % (int)(20 - 10 + 1));
	}
	else
	{
		m_resistance = 10 + (rand() % (int)(15 - 10 + 1));
	}
}
