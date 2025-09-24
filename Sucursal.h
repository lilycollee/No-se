#pragma once
#include<iostream>
#include<sstream>
#include <string>
#include "Instructor.h"
#include "Cliente.h"
#include "SesionGrupal.h"
using namespace std;

int const maxInstructores = 20;
int const maxClientes = 100;
int const maxSesiones = 8;

class Sucursal {
private:
	string nombre;
	string provincia;
	string canton;
	string telefono;
	string email;
	int codigo;
	Instructor** instructores;
	Cliente** clientes;
	SesionGrupal** sesiones;
	int cantInstructores;
	int cantClientes;
	int cantSesiones;

public:
	//------------------Constructores------------------
	Sucursal();
	Sucursal crearSucursal(string, string, string, string, string, int);

	//------------------Metodos get------------------
	string get_Nombre();
	string get_Provincia();
	string get_Canton();
	string get_Telefono();
	string get_Email();
	int get_Codigo();

	//------------------Metodos set------------------
	void set_Nombre(string);
	void set_Provincia(string);
	void set_Canton(string);
	void set_Telefono(string);
	void set_Email(string);
	void set_Codigo(int);

	//------------------Metodos propios------------------
	void agregarInstructor(Instructor*);
	void agregarCliente(Cliente*);
	void agregarSesion(SesionGrupal*);
	string tostring();
	~Sucursal();
};

