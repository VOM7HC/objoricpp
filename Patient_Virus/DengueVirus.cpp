#include "stdafx.h"
#include "DengueVirus.h"


DengueVirus::DengueVirus()
{
	InitResistance();
	DoBorn();
}


DengueVirus::~DengueVirus()
{
	DoDie();
}

void DengueVirus::DoBorn()
{
	LoadADNInformation();
	int rannum = 1 + (rand() % (int)(3 - 1 + 1));
	if (rannum == 1)
	{
		std::string str("NS3");
		str.copy(m_protein, 3);
		m_protein[3] = '\0';
	}
	if (rannum == 2)
	{
		std::string str("NS5");
		str.copy(m_protein, 3);
		m_protein[3] = '\0';
	}
	if (rannum == 3)
	{
		std::string str("E");
		str.copy(m_protein, 1);
		m_protein[1] = '\0';
	}
}

std::list<Virus*> DengueVirus::DoClone()
{
	DengueVirus *other1 = new DengueVirus;
	DengueVirus *other2 = new DengueVirus;
	std::list<Virus*> tempLst;
	
	*other1->m_protein = *this->m_protein;
	other1->m_dna = this->m_dna;
	other1->m_resistance = this->m_resistance;
	*other2->m_protein = *this->m_protein;
	other2->m_dna = this->m_dna;
	other2->m_resistance = this->m_resistance;

	tempLst.push_back(other1);
	tempLst.push_back(other2);

	other1 = NULL;
	delete other1;
	other2 = NULL;	
	delete other2;

	return tempLst;
	tempLst.clear();
}

void DengueVirus::DoDie()
{
	this->m_dna = NULL;
	*this->m_protein = NULL;
	this->m_resistance = NULL;

	delete this;
}

void DengueVirus::InitResistance()
{
	if (m_protein == "NS3")
	{
		m_resistance = 1 + (rand() % (int)(10 - 1 + 1));
	}
	if (m_protein == "NS5")
	{
		m_resistance = 11 + (rand() % (int)(20 - 11 + 1));
	}
	if (m_protein == "E")
	{
		m_resistance = 21 + (rand() % (int)(30 - 21 + 1));
	}
}
