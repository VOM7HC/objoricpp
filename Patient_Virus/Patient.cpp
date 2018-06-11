#include "stdafx.h"
#include "Patient.h"
#include "Fluvirus.h"
#include "DengueVirus.h"

Patient::Patient()
{
	InitResistance();
	DoStart();
}

Patient::~Patient()
{
}

void Patient::InitResistance()
{
	m_resistance = 1000 + (rand() % (int)(9000 - 1000 + 1));
}

void Patient::DoStart()
{
	m_state = 1;

	int numvirus = 10 + (rand() % (int)(20 - 10 + 1));
	for (int i = 0; i < numvirus; i++)
	{
		if (i % 2 == 0)
		{
			Virus *deng = new DengueVirus;
			m_virusList.push_back(deng);
		}
		else
		{
			Fluvirus *flu = new Fluvirus;
			m_virusList.push_back(flu);
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	for (auto const& it : m_virusList)
	{
		std::list<Virus*> tempLst;
		tempLst = it->ReduceResistance(medicine_resistance);
		for (auto const& it2 : tempLst)
		{
			m_virusList.push_back(it2);
		}
	}
	int tempVirusPower = 0;
	for (auto const& it : m_virusList)
	{
		tempVirusPower += it->GetResist();
	}
	if (m_resistance - tempVirusPower <= 0)
	{
		this->DoDie();
	}
}

void Patient::DoDie()
{
	m_state = 0;
	m_virusList.clear();
}

int Patient::GetState()
{
	return m_state;
}
