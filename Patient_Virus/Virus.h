#include <cstdlib>
#include <list>

#pragma once
class Virus
{
public:
	Virus();
	Virus(const Virus& other) : m_dna(other.m_dna), m_resistance(other.m_resistance) {};
	virtual ~Virus();
	void LoadADNInformation();
	int ReduceResistance(int medicine_resistance);

	virtual void DoBorn() = 0;
	virtual std::list<Virus*> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;

	int Virus::GetResist();
protected:
	char* m_dna;
	int m_resistance;

};

