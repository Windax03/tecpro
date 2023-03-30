public interface VMPElectrico
{
	static final double precio = 1.0;

	double  carga();
	void    carga(double c);
	boolean cargando();
};
