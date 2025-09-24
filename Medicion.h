#pragma once
#include<iostream>
#include<sstream>
#include <string>
#include "Cliente.h"
#include "Instructor.h"
using namespace std;

class Medicion {
private:
	int fecha[3];
	float peso;
	float estatura;
	float porcentajeGrasa;
	float porcentajeMusculo;
	float edadMetabolica;
	float cintura;
	float cadera;
	float pecho;
	float muslo;
	Cliente* clienteUno;
	Instructor* instructor;
public:

	//------------------Constructores------------------
	Medicion();

	//------------------Metodos get------------------
	string get_Fecha();
	float get_Peso();
	float get_Estatura();
	float get_PorcentajeGrasa();
	float get_PorcentajeMusculo();
	int get_EdadMetabolica();
	float get_Cintura();
	float get_Cadera();
	float get_Pecho();
	float get_Muslo();

	//------------------Metodos set------------------
	void set_Peso(float);
	void set_Estatura(float);
	void set_PorcentajeGrasa(float);
	void set_PorcentajeMusculo(float);
	void set_EdadMetabolica(float);
	void set_Cintura(float);
	void set_Cadera(float);
	void set_Pecho(float);
	void set_Muslo(float);
	void set_Cliente(Cliente&);
	void set_Instructor(Instructor&);

	//------------------Destructor------------------
	~Medicion();

	//------------------Metodos propios------------------
	float calcularIMC();
	string clasifIMC();
	float calcularGramosProt();
	float vasosAgua();
	string reporte();
};

