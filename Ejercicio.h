#include<iostream>
#include<sstream>
#include <string>
using namespace std;

class Ejercicio {
private:
	string nombre;
	string area;
	string descripcion;
	int series;
	int repeticiones;

public:

	//------------------Constructores------------------
	Ejercicio();
	Ejercicio(string, string, string, int, int);

	//------------------Metodos get--------------------
	string get_Nombre();
	string get_Area();
	string get_Descripcion();
	int get_Series();
	int get_Repeticiones();

	//------------------Metodos set--------------------

	void set_Nombre(string);
	void set_Area(string);
	void set_Descripcion(string);
	void set_Series(int);
	void set_Repeticiones(int);

	//------------------Destructor---------------------
	~Ejercicio();

	//------------------Metodos Propios----------------
	string mostrarEjercicio();

};

