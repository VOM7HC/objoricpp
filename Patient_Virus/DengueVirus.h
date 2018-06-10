#include "Virus.h"
#include <string>
#pragma once
class DengueVirus : public Virus
{
public:
	DengueVirus();
	~DengueVirus();

	void DoBorn();
	std::list<Virus*> DoClone();
	void DoDie();
	void InitResistance();
private:
	char m_protein[4];
};

