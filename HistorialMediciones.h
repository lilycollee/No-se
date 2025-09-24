#pragma once
#include<iostream>
#include "Medicion.h"
using namespace std;

int const MAX_MEDICIONES = 10;

class HistorialMediciones {
private:
	Medicion* mediciones[MAX_MEDICIONES];
	int cantidad;
public:
	//------------------Constructores------------------
	HistorialMediciones();

	//------------------Metodos get-------------------
	int get_CantidadMediciones() const;
	Medicion* get_Medicion(int) const;

	//------------------Destructor--------------------
	~HistorialMediciones();

	//------------------Metodos Propios---------------
	bool agregar_Medicion(Medicion*);
	bool eliminar_Medicion(int);
	string mostrar_HistorialMediciones();
};

