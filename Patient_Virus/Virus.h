#include <cstdlib>
#include <list>

#pragma once
class Virus
{
public:
	Virus();
	virtual ~Virus();
	void LoadADNInformation();
	std::list<Virus*> ReduceResistance(int medicine_resistance);

	virtual void DoBorn();
	virtual std::list<Virus*> DoClone();
	virtual void DoDie();
	virtual void InitResistance();

	int Virus::GetResist();
protected:
	char* m_dna;
	int m_resistance;

};

