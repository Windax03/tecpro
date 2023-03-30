#include "flota.h"

void Flota::annade(VMP* v)
{
	vmps.push_back(v);
}

const Flota::VMPS& Flota::lista() const
{
	return vmps;
}

VMP* Flota::masLejano() const
{
	VMP* tgt=nullptr;
	double maxd = 0;
	for (auto v : vmps)
	{
		double vd = v->distancia();
		if (vd>maxd)
		{
			tgt  = v;
			maxd = vd;
		}
	}

	return tgt;
}

Flota::VMPS Flota::fueraDeArea(double r) const
{
	VMPS out;

	for (auto v : vmps)
	{
		if (v->disponible() && !v->aparcado() && (v->distancia()>r))
		{
			v->bloquear();
			out.push_back(v);
		}
	}

	return out;
}

Flota::VMPS Flota::cargaBaja(double cargaMin) const
{
	VMPS out;

	for (auto v : vmps)
	{
		VMPElectrico* ve = dynamic_cast<VMPElectrico*>(v);
		if (ve)
		{
			if (!ve->cargando() && (ve->carga()<cargaMin))
			{
				ve->bloquear();
				out.push_back(ve);
			}
		}
	}

	return out;
}

double Flota::patinetesEnUso() const
{
	int   nu=0, np=0;
	double ratio = 0.0;

	for (auto v : vmps)
	{
		if (!v->disponible() && !v->aparcado())
		{
			nu++;
			if (dynamic_cast<Patinete*>(v)!=nullptr) np++;
		}
	}
	if (nu>0) ratio = 100*(double(np)/double(nu));

	return ratio;
}
