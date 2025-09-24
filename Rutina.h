#pragma once
#include<iostream>
#include<sstream>
#include "Ejercicio.h"
#include "Instructor.h"
using namespace std;

int const MAX_EJERCICIOS = 10;

class Rutina {
private:
	int fecha[3]; //dia, mes, anio
	Ejercicio* eje[MAX_EJERCICIOS];
	Instructor* instructor;
	int cant;

public:

	//------------------Constructores-----------------
	Rutina();

	//------------------Metodos get-------------------
	string get_Fecha();
	Ejercicio* get_Ejercicio(string);  //recibe el nombre del ejercicio
	Instructor* get_Instructor();
	int get_CantidadEjercicios() const;

	//------------------Metodos set-------------------
	void set_Fecha(int, int, int); //
	void set_ejercicio(string, Ejercicio*);
	void set_instructor(Instructor*);

	//------------------Destructor--------------------
	~Rutina();

	//------------------Metodos Propios---------------
	bool agregar_Ejercicio(Ejercicio*);
	bool eliminar_Ejercicio(string);
	string Mostrar_Rutina();

};

