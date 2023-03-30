#pragma once

using namespace std;

class VMP
{
private:
	int		id;
	double	x,y;
	bool	estaEnBase;
	bool	estaDisponible;

public:
	VMP(int _id,double _x,double _y);

	int    identificador() const;
	double distancia() const;

	bool   disponible() const;
	void   liberar();
	void   bloquear();

	bool   aparcado() const;

	virtual void  alquilar();
	virtual void  devolver();

	virtual double coste() const = 0;
};

class VMPElectrico : virtual public VMP
{
protected:
	static constexpr double precio = 1.0;
private:
	double	cargaBateria;
	bool	estaCargando;
public:
	VMPElectrico();

	double carga() const;
	void   carga(double c);
	bool   cargando() const;

	void   alquilar() override;
	void   devolver() override;

	double coste() const;
};

class Bicicleta : virtual public VMP
{
protected:
	static constexpr double precio = 2.0;
public:
	Bicicleta(int _id,double _x,double _y);
	double coste() const override;
};

class BicicletaElectrica :  public Bicicleta, public VMPElectrico
{
public:
	BicicletaElectrica(int _id,double _x,double _y);
	double coste() const override;
};

class Patinete : virtual public VMP
{
protected:
	static constexpr double precio = 1.5;
public:
	Patinete(int _id,double _x,double _y);
	double coste() const override;
};

class PatineteElectrico : public Patinete, public VMPElectrico
{
public:
	PatineteElectrico(int _id,double _x,double _y);
	double coste() const override;
};
