#include "Instructor.h"
#include "Medicion.h"
#include "Rutina.h"
#include "SesionGrupal.h"
#include "HistorialMediciones.h"
#include "Cliente.h"

//------------------Constructores------------------
Cliente::Cliente() {
	nombre = "Desconocido";
	cedula = "-";
	telefono = 0;
	email = "Desconocido";
	fechaNac[0] = 0, fechaNac[1] = 0, fechaNac[2] = 0;
	sexo = '-';
	fechaIns[0] = 0, fechaIns[1] = 0, fechaIns[2] = 0;
	insAsignado = new Instructor();
	rutActual = new Rutina();
	cantSG = 0;
	cantMedi = 0;
	for (int i = 0; i < 3; i++) {
		clasesMatriculadas[i] = nullptr;
	}
	for (int i = 0; i < 10; i++) {
		historialMediciones[i] = nullptr;
	}
}
// Cambia la firma del constructor para que coincida con la declaración en Cliente.h
Cliente::Cliente(string n, string c, int tel, string e, int dN, int mN, int aN, char s, Instructor& ins, int dI, int mI, int aI) {
	nombre = n;
	cedula = c;
	telefono = tel;
	email = e;
	fechaNac[0] = dN; fechaNac[1] = mN; fechaNac[2] = aN;
	sexo = s;
	fechaIns[0] = dI; fechaIns[1] = mI; fechaIns[2] = aI;
	insAsignado = new Instructor(ins);
	cantSG = 0;
	cantMedi = 0;
	rutActual = new Rutina();
	for (int i = 0; i < 3; i++) {
		clasesMatriculadas[i] = nullptr;
	}
	for (int i = 0; i < 10; i++) {
		historialMediciones[i] = nullptr;
	}
}

//------------------Metodos get------------------
string Cliente::get_Nombre() { return nombre; }

string Cliente::get_Cedula() { return cedula; }

int Cliente::get_Telefono() { return telefono; }

string Cliente::get_Email() { return email; }

string Cliente::get_FechaNacimiento() {
	stringstream s;
	s << fechaNac[0] << " / " << fechaNac[1] << " / " << fechaNac[2];
	return s.str();
};

char Cliente::get_Sexo() { return sexo; }

string Cliente::get_fechaInscripcion() {
	stringstream s;
	s << fechaIns[0] << " / " << fechaIns[1] << " / " << fechaIns[2];
	return s.str();
}

Instructor* Cliente::get_InstructorAsignado() { return insAsignado; }

SesionGrupal* Cliente::get_ClasePorCodigo(int cod){
	for (int i = 0; i < cantSG; i++) {
		if (clasesMatriculadas[i]->get_Codigo() == cod)
			return clasesMatriculadas[i];
	}
}

string Cliente::get_HistorialMediciones() {};

string Cliente::mostrar_ClasesMatriculadas() {
	stringstream ss;
	for (int i = 0; i < cantSG; i++)
		ss << clasesMatriculadas[i]->toString() << endl;

	return ss.str();
};

//------------------Metodos set------------------
void Cliente::set_Nombre(string nom) { nombre = nom; };

void Cliente::set_Cedula(string id) { cedula = id; };

void Cliente::set_Telefono(int tel) { telefono = tel; };

void Cliente::set_Email(string em) { email = em; };

void Cliente::set_FechaNac(int d, int m, int a)
{
	fechaNac[0] = d;
	fechaNac[1] = m;
	fechaNac[2] = a;
};

void Cliente::set_Sexo(char s) { sexo = s; };

void Cliente::set_FechaInscripcion(int dia, int mes, int ann)
{
	fechaIns[0] = dia;
	fechaIns[1] = mes;
	fechaIns[2] = ann;
};

void Cliente::set_InstructorAsignado(Instructor* ins) { insAsignado = ins; }

void Cliente::set_Rutina(Rutina& ruti) { rutActual = &ruti; }

//----------------------Metodos propios------------------------------
bool Cliente::inscribir_SG(SesionGrupal& sg) {
	if (cantSG < 3) {
		if (buscar_SG(sg.get_Codigo())) // evitar doble inscripción
			return false;
        clasesMatriculadas[cantSG] = &sg;
		cantSG++;
		return true;
	}
	return false;
}

bool Cliente::buscar_SG(int cod) {
	if (cantSG < 3)
		for (int i = 0; i < cantSG; i++) {
			if (clasesMatriculadas[i]->get_Codigo() == cod)
				return true;
		}

	return false;
}
bool Cliente::cancelar_SG(int cod) {
	if (buscar_SG(cod)) {
		for (int i = 0; i < cantSG; i++) {
			if (clasesMatriculadas[i]->get_Codigo() == cod) {
				for (int j = i; j < cantSG - 1; j++)
					clasesMatriculadas[j] = clasesMatriculadas[j + 1];
				clasesMatriculadas[cantSG - 1] = nullptr;
				cantSG--;
				return true;
			}
		}
	}
	return false;
}

string Cliente::datos_CLiente() {
	stringstream s;
	s << "-------- Datos del Cliente --------" << endl << endl;
	s << "Nombre: " << nombre << endl;
	s << "Cedula: " << cedula << endl;
	s << "Telefono: " << telefono << endl;
	s << "Email: " << email << endl;
	s << "Fecha de Nacimiento: " << get_FechaNacimiento() << endl;
	s << "Sexo: " << sexo << endl;
	s << "Fecha de Inscripcion: " << get_fechaInscripcion() << endl;
	s << "Instructor Asignado: " << insAsignado->get_Nombre() << endl;
	s << "Clases Grupales Matriculadas: " << endl;
	for (int i = 0; i < cantSG; i++) {
		s << "\t" << i + 1 << ": " << clasesMatriculadas[i]->get_Nombre() << "\t" << clasesMatriculadas[i]->get_Codigo() << endl;
	}
	s << "----------------------------------" << endl;
	return s.str();
};

Cliente::~Cliente() {
	delete insAsignado;
	delete rutActual;
	for (int i = 0; i < cantSG; i++)
		clasesMatriculadas[i] = nullptr; // no borras porque no eres dueño
	for (int i = 0; i < cantMedi; i++)
		historialMediciones[i] = nullptr;
}

