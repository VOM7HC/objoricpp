#include "stdafx.h"
#include "Virus.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Patient.h"

Virus::Virus()
{
	m_dna = nullptr;
}

Virus::~Virus()
{
	if (m_dna)
	{
		delete m_dna;
		m_dna = nullptr;
	}
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

int Virus::ReduceResistance(int medicine_resistance)
{
	m_resistance = m_resistance - medicine_resistance;
	if (m_resistance <= 0)
		return 1;
	else
		return 0;
}

std::list<Virus*> Virus::DoClone()
{
	std::list<Virus*> tempLst;
	return tempLst;
}

int Virus::GetResist()
{
	return m_resistance;
}
