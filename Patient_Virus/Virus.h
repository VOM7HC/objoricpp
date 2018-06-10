#include <cstdlib>
#include <list>

#pragma once
class Virus
{
public:
	Virus();
	~Virus();
	void LoadADNInformation();
	void ReduceResistance(int medicine_resistance);

	virtual void DoBorn();
	virtual std::list<Virus*> DoClone();
	virtual void DoDie();
	virtual void InitResistance();
protected:
	char* m_dna;
	int m_resistance;

};

