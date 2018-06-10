#include "stdafx.h"
#include "Patient.h"
#include "Fluvirus.h"
#include "DengueVirus.h"

Patient::Patient()
{
	m_state = 1;
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
			DengueVirus *deng = new DengueVirus;
			m_virusList.push_back(deng);

			deng = NULL;
			delete deng;
		}
		else
		{
			Fluvirus *flu = new Fluvirus;
			m_virusList.push_back(flu);

			flu = NULL;
			delete flu;
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	for (std::list<Virus*>::iterator it = m_virusList.begin(); it != m_virusList.end(); it++)
	{
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
