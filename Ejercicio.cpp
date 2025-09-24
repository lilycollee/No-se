#include "Ejercicio.h"

//------------------Constructores------------------
Ejercicio::Ejercicio() : nombre("Sin definir"), area("Sin definir"), descripcion("Sin una descripcion"), series(0), repeticiones(0) {}

Ejercicio::Ejercicio(string nombre_, string area_, string descripcion_, int series_, int repeticiones_) {
	nombre = nombre_;
	area = area_;
	descripcion = descripcion_;
	series = series_;
	repeticiones = repeticiones_;
}

//------------------Metodos get------------------
string Ejercicio::get_Nombre() { return nombre; }

string Ejercicio::get_Area() { return area; }

string Ejercicio::get_Descripcion() { return descripcion; }

int Ejercicio::get_Series() { return series; }

int Ejercicio::get_Repeticiones() { return repeticiones; }

//------------------Metodos set------------------

void Ejercicio::set_Nombre(string nombre_) { nombre = nombre_; }

void Ejercicio::set_Area(string area_) { area = area_; }

void Ejercicio::set_Descripcion(string descripcion_) { descripcion = descripcion_; }

void Ejercicio::set_Series(int series_) { series = series_; };

void Ejercicio::set_Repeticiones(int repeticiones_) { repeticiones = repeticiones_; }

//------------------Destructor------------------
Ejercicio::~Ejercicio() {}

//------------------Metodos propios------------------
string Ejercicio::mostrarEjercicio() {
	stringstream s;
	s << "Nombre del ejercicio: " << nombre << endl;
	s << "Area a trabajar: " << area << endl;
	s << "Descripcion del ejercicio: " << endl << descripcion << endl;
	s << "Cantidad de series: " << series << endl;
	s << "Cantidad de repeticiones: " << repeticiones << endl;
	return s.str();
}
