#pragma once
#include<iostream>
#include<sstream>
#include <string>
#include "Cliente.h"
#include "Medicion.h"
#include "Rutina.h"
using namespace std;

int const MAX_ESPECIALIDADES = 8;
int const MAX_CLIENTES = 20;
int const MAX_REPORTES = 10;

class Instructor {
private:
	string nombre;
	string cedula;
	int telefono;
	string email;
	char sexo;
	int fechaNacimiento[3];
	string especialidad[MAX_ESPECIALIDADES];
	Cliente** clientesAsignados; 
	Medicion* reportes[MAX_REPORTES];
	int cantEspe;

public:
	//------------------Constructores------------------
	Instructor();
	Instructor(string, string, int, string, int, int, int, char);

	//------------------Metodos get------------------
	string get_Nombre();
	string get_Cedula();
	int get_Telefono();
	string get_Email();
	string get_FechaNacimiento();
	string get_Especialidades();

	//------------------Metodos set------------------
	void set_Nombre(string);
	void set_Cedula(string);
	void set_Telefono(int);
	void set_Email(string);
	void set_FechaNacimiento(int, int, int);


	//------------------Destructor------------------
	~Instructor();

	//------------------Metodos propios------------------
	string tostring();
	bool agregar_Especialidad(string);
	void hacer_Medicion(Medicion&); //Cliente*
};

