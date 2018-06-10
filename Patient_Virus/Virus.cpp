#include "stdafx.h"
#include "Virus.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>

Virus::Virus()
{
}


Virus::~Virus()
{
	//DoDie;
}

void Virus::LoadADNInformation()
{
	std::ifstream input("E:/ATGX.bin");
	std::string line;

	std::getline(input, line);
	
	m_dna = new char[line.size()+1];
	std::copy(line.begin(), line.end(), m_dna);
	m_dna[line.size()] = '\0';
}

void Virus::ReduceResistance(int medicine_resistance)
{
	m_resistance = m_resistance - medicine_resistance;
	if (m_resistance <= 0)
	{
		this->~Virus();
	}
}

void Virus::DoBorn()
{
}

std::list<Virus*> Virus::DoClone()
{
	std::list<Virus*> tempLst;
	return tempLst;
}

void Virus::DoDie()
{
	this->m_dna = NULL;
	this->m_resistance = NULL;

	delete this;
}

void Virus::InitResistance()
{
}
