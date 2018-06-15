#include "stdafx.h"
#include "Patient.h"
#include "Fluvirus.h"
#include "DengueVirus.h"
#include <algorithm>

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
			Virus *flu = new Fluvirus;
			m_virusList.push_back(flu);
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance)
{
	std::list<Virus*> toAdded;
	for (std::list<Virus*>::iterator it = m_virusList.begin(); it != m_virusList.end(); it++)
	{
		int res = (*it)->ReduceResistance(medicine_resistance);
		if (res == 1)
		{
			Virus* virus = *it;
			*it = nullptr;

			delete virus;
			virus = nullptr;
		}
		else
		{
			std::list<Virus*> tempLst = (*it)->DoClone();
			for (auto it2 : tempLst)
			{
				toAdded.push_back(it2);
			}
		}
	}

	m_virusList.remove(nullptr);

	for (auto it : toAdded)
	{
		m_virusList.push_back(it);
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
