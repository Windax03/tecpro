#pragma once

#include "vmp.h"
#include <vector>
#include <list>

using namespace std;

class Flota
{
public:
	using VMPS = vector<VMP*>;
	//using VMPS = list<VMP*>;

public:
	VMPS vmps;

public:
	void		annade(VMP* v);
	const VMPS&	lista() const;
	VMP*		masLejano() const;
	VMPS		fueraDeArea(double r) const;
	VMPS		cargaBaja(double cargaMin) const;
	double		patinetesEnUso() const;
};
