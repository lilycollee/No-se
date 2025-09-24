#pragma once
#include<iostream>
#include<sstream>
#include <string>
#include "Instructor.h"
#include "Cliente.h" 
using namespace std;

int const max_clientes = 20;

class SesionGrupal{
private:
	int codigo;
	string nombre;
	string salon;
	int horario[4]; // Empieza [hora]:[minuto]/ Termina[hora]:[minuto]
	int cupoMax;
	Instructor* instructor;
	Cliente** clientesInscritos;
public:
	//------------------Constructores------------------
	SesionGrupal();
	SesionGrupal(Instructor*, string, string, int, int, int, int, int, int);

	//------------------Metodos set------------------
	void set_Instructor(Instructor*);
	void set_Salon(string);
	void set_HoraInicio(int, int);
	void set_HoraFinal(int, int);

	//------------------Metodos get------------------
	int get_Codigo();
	string get_Nombre();
	string get_Salon();
	int get_CupoMax();
	Instructor* get_Instructor();
	string get_Horario();

	//------------------Metodos propios--------------------
	string toString();
	bool inscribir_Cliente(Cliente&);
	bool eliminar_Cliente(string);
	string mostrar_ClientesInscritos();

	//------------------Destructor------------------
	~SesionGrupal();
};
