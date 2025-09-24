#pragma once
#include<iostream>
#include<sstream>
#include <string>
#include "Instructor.h"
#include "Medicion.h"
#include "Rutina.h"
#include "SesionGrupal.h"
#include "HistorialMediciones.h"
using namespace std;

class Cliente {
private:
	string nombre;
	string cedula;
	int telefono;
	string email;
	int fechaNac[3];
	char sexo;
	int fechaIns[3];
	Instructor* insAsignado;
	Rutina* rutActual;
	HistorialMediciones* historialMediciones[10];
	SesionGrupal* clasesMatriculadas[3];
	int cantSG;
	int cantMedi;
public:
	//------------------Constructores------------------
	Cliente();
	Cliente(string, string, int, string, int, int, int, char, Instructor&, int, int, int);

	//------------------Metodos get------------------
	string get_Nombre();
	string get_Cedula();
	int get_Telefono();
	string get_Email();
	string get_FechaNacimiento();
	char get_Sexo();
	string get_fechaInscripcion();
	Instructor* get_InstructorAsignado();
	SesionGrupal* get_ClasePorCodigo(int);
	string get_HistorialMediciones(); //preguntar a la profesora si hay que devolverlos todos o uno en especifico (tambien si hay que devolverlos por fecha)
	string mostrar_ClasesMatriculadas();

	//------------------Metodos set------------------
	void set_Nombre(string);
	void set_Cedula(string);
	void set_Telefono(int);
	void set_Email(string);
	void set_FechaNac(int, int, int);
	void set_Sexo(char);
	void set_FechaInscripcion(int, int, int);
	void set_InstructorAsignado(Instructor*);
	void set_Rutina(Rutina&);

	//------------------Metodos propios--------------------
	bool inscribir_SG(SesionGrupal&);
	bool buscar_SG(int);
	bool cancelar_SG(int);
	string datos_CLiente();

	//---------------------Destructor----------------------
	~Cliente();
};

